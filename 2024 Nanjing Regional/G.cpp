#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10,M=N*2;
int h[N],e[M],ne[M],idx;
bool st[N];
int n;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int get_size(int u,int father)
{
    if(st[u]) return 0;
    int sz=1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        sz+=get_size(j,u);
    }
    return sz;
}

vector<int> get_son(int u)
{
    vector<int>v;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(st[j]) continue;
        v.push_back(j);
    }
    sort(v.begin(),v.end(),[](int a,int b){
        return get_size(a,-1)>get_size(b,-1);
    });
    return v;
}

int get_wc(int u,int father,int tot,int& wc)
{
    if(st[u]) return 0;
    int sum=1,ms=0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        int t=get_wc(j,u,tot,wc);
        ms=max(ms,t);
        sum+=t;
    }
    ms=max(ms,tot-sum);
    if(ms<=tot/2) wc=u;
    return sum;
}

int work(int u,int v)
{
    cout<<"? "<<u<<' '<<v<<endl;
    fflush(stdout);
    
    int t;
    cin>>t;
    return t;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) h[i]=-1,st[i]=false;
    idx=0;

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x) add(i,x),add(x,i);
        if(y) add(i,y),add(y,i);
    }

    int U=1;
    while(true)
    {
        int wc=U;
        int tot=get_size(U,-1);
        get_wc(U,-1,tot,wc);
        st[wc]=true;

        vector<int>son=get_son(wc);
        if(son.size()==0)
        {
            cout<<"! "<<wc<<endl;
            fflush(stdout);
            return;
        }
        else if(son.size()==1)
        {
            int u=son[0],v=wc;
            int t=work(u,v);
            if(t==0)
            {
                cout<<"! "<<u<<endl;
                fflush(stdout);
                return;
            }
            else if(t==2)
            {
                cout<<"! "<<v<<endl;
                fflush(stdout);
                return;
            }
        }
        else if(son.size()==2)
        {
            int u=son[0];
            int v=son[1];
            int t=work(u,v);
            if(t==0) U=u;
            else if(t==1)
            {
                cout<<"! "<<wc<<endl;
                fflush(stdout);
                return;
            }
            else U=v;
        }
        else // v.size()==3
        {
            int u=son[0];
            int v=son[1];
            int w=son[2];
            int t=work(u,v);
            if(t==0) U=u;
            else if(t==1)
            {
                U=wc;
                st[wc]=false;
                st[u]=true;
                st[v]=true;
            }
            else U=v;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
