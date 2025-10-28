#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=10,M=70,INF=1e15;
int n,m,K,R;
int a[N],c[N];
int A[M][M];

void mul(int a[M][M],int b[M][M],int c[M][M])
{
    int res[M][M]={0};
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
            res[i][j]=-INF;
    for(int k=0;k<(1<<n);k++)
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<(1<<n);j++)
                res[i][j]=max(res[i][j],a[i][k]+b[k][j]);
    memcpy(c,res,sizeof res);
}

void qmi(int a[M][M],int N,int c[M][M])
{
    int res[M][M]={0};
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
            if(i!=j) res[i][j]=-INF;
    while(N)
    {
        if(N&1) mul(res,a,res);
        mul(a,a,a);
        N>>=1;
    }
    memcpy(c,res,sizeof res);
}

void solve()
{
    cin>>n>>m>>K>>R;
    for(int i=0;i<n;i++) cin>>a[i]>>c[i];
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
        {
            int cost=0;
            int damage=0;
            for(int k=0;k<n;k++)
                if(i>>k&1)
                {
                    if(j>>k&1) cost+=c[k]+K;
                    else cost+=c[k];
                    damage+=a[k];
                }
            if(cost>m) damage=-1e18;
            A[i][j]=damage;
        }
    int res=-INF;
    qmi(A,R,A);
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
            res=max(res,A[i][j]);
    cout<<res<<'\n';
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
