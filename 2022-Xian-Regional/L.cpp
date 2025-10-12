#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N=1e6+10,M=N*2;
int h[N],e[M],ne[M],idx;
int fa[N],din[N],val[N];
bool del[N],st[N];
struct Node
{
    int x,len;

    bool operator < (const Node& t) const
    {
        if(len!=t.len) return len>t.len;
        return x<t.x;
    }
};
set<Node>s;
int n;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int res;
void dfs(int u,int father,int len)
{
    fa[u]=father;
    if(din[u]==1)
    {
        s.insert({u,len});
        res=max(res,len);
        val[u]=len;
    }
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        dfs(j,u,len+1);
    }
}

void update_leaf(int u,int len)
{
    if(din[u]==1&&!st[u])
    {
        s.erase({u,val[u]});
        s.insert({u,len});
        val[u]=len;
        //cout<<u<<' '<<len<<endl;
    }
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==fa[u]) continue;
        if(st[j]) continue;
        update_leaf(j,len+1);
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        h[i]=-1;
        fa[i]=0;
        din[i]=0;
        val[i]=0;
        del[i]=false;
        st[i]=false;
    }
    idx=0;
    s.clear();

    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        add(i,p),add(p,i);
        din[i]++,din[p]++;
    }
    din[1]=0;

    if(n==1)
    {
        cout<<1<<'\n';
        return;
    }

    res=0;
    dfs(1,0,1);
    int del_tot=0;
    while(!s.empty())
    {
        auto it=s.begin();
        int x=it->x,len=it->len;
        s.erase(it);
        if(st[x]) continue;
        del_tot++;

        int u=x;
        while(!st[u])
        {
            st[u]=true;
            update_leaf(u,0);
            if(u==1) break;
            u=fa[u];
        }

        int maxLen=0;
        while(!s.empty())
        {
            auto it=s.begin();
            int x=it->x,len=it->len;
            if(st[x])
            {
                s.erase(it);
                continue;
            }
            maxLen=len;
            break;
        }
        res=min(res,del_tot+maxLen);
    }
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}