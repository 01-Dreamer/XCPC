#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10,M=N*2;
int h[N],e[M],ne[M],idx;
int p[N],q[N],fa[N];
bool st[N];
int n;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) h[i]=-1,p[i]=i,fa[i]=0,st[i]=false;
    idx=0;

    for(int i=1;i<=n;i++) cin>>q[i];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }

    for(int i=n;i>=1;i--)
    {
        int u=q[i];
        st[u]=true;
        for(int j=h[u];~j;j=ne[j])
        {
            int v=e[j];
            int pv=find(v);
            if(!st[pv]) continue;
            fa[pv]=u;
            p[pv]=u;
        }
    }

    for(int i=1;i<=n;i++) cout<<fa[i]<<' ';
    cout<<'\n';
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