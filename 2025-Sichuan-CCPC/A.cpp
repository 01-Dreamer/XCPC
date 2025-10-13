#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=310,M=1010;
int h[N],e[M],ne[M],wa[M],wb[M],idx;
int n,m;

void add(int a,int b,int c1,int c2)
{
    e[idx]=b,wa[idx]=c1,wb[idx]=c2,ne[idx]=h[a],h[a]=idx++;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) h[i]=-1;
    idx=0;
    int maxa=-2e9;
    for(int i=0;i<m;i++)
    {
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        add(u,v,a,b);
        maxa=max(maxa,a);
    }

    vector<vector<int>>f(n+1,vector<int>(n*maxa+1,1e12));
    f[1][0]=0;
    for(int j=0;j<=n*maxa;j++)
        for(int i=1;i<=n;i++)
        {
            if(f[i][j]>=1e12) continue;
            for(int k=h[i];~k;k=ne[k])
            {
                int u=e[k];
                if(j+wa[k]>n*maxa) continue;
                f[u][j+wa[k]]=min(f[u][j+wa[k]],f[i][j]+wb[k]);
            }
        }
    
    int A,B,minv=1e18;
    for(int j=1;j<=n*maxa;j++)
            if(f[n][j]<1e12&&j*f[n][j]<minv) A=j,B=f[n][j],minv=j*f[n][j];
    cout<<A<<' '<<B<<'\n';
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
