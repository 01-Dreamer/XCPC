#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=3e5+10,M=2e6+10;
int h[N],e[M],ne[M],w[M],idx;
int d1[N],dn[N];
struct Node
{
    int a,b,c;
    bool operator < (const Node& t) const
    {
        return c<t.c;
    }
}edges[M/2];
int p[N];
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void kruskal()
{
    for(int i=0;i<m;i++)
    {
        Node& t=edges[i];
        int a=find(t.a),b=find(t.b);
        if(a!=b)
        {
            p[a]=b;
            add(a,b,t.c);
            add(b,a,t.c);
        }
    }
}

void dfs(int u,int father,int M[])
{
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        M[j]=max(M[u],w[i]);
        dfs(j,u,M);
    }
}

void solve()
{
    memset(h,-1,sizeof h);

    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;

    int res=2e9;
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].c;
        if(edges[i].a==1&&edges[i].b==n) res=min(res,edges[i].c);
        if(edges[i].a==n&&edges[i].b==1) res=min(res,edges[i].c);
    }
    sort(edges,edges+m);
    kruskal();

    dfs(1,-1,d1);
    dfs(n,-1,dn);

    for(int i=0;i<m;i++)
    {
        Node& t=edges[i];
        int val=max(d1[t.a],dn[t.b]);
        if(t.c>=val) res=min(res,t.c+val);
        val=max(d1[t.b],dn[t.a]);
        if(t.c>=val) res=min(res,t.c+val);
    }
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    //cin>>T;
    while(T--) solve();

    return 0;
}