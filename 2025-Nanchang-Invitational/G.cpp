#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10,M=5e5+10,K=31;
int h[N],e[M],ne[M],w[M],idx;
int d[N][K];
int n,m,q;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void solve()
{
    memset(h,-1,sizeof h);
    idx=0;

    cin>>n>>m>>q;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    for(int i=1;i<=n;i++) d[i][0]=1;
    for(int j=1;j<K;j++)
        for(int i=1;i<=n;i++)
            for(int k=h[i];~k;k=ne[k])
                d[i][j]=max(d[i][j],min(d[e[k]][j-1]*w[k],1000000001LL));

    while(q--)
    {
        int p,x;
        cin>>p>>x;
        for(int j=1;j<K;j++)
            if(d[p][j]>x)
            {
                cout<<j<<'\n';
                break;
            }
    }
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
