#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<double>r(n+1,0),c(n+1,0);
    double p,L,R;
    cin>>r[0]>>c[0]>>p>>L>>R;
    for(int i=1;i<=n;i++) r[i]=L;
    for(int i=0;i<k;i++)
    {
        int x;
        double v;
        cin>>x>>v;
        r[x]=v;
    }
    for(int i=1;i<=n;i++) c[i]=p*c[i-1]+(1-p)*r[i-1];

    double res=0;
    for(int i=1;i<=n;i++) res+=c[i]-r[i];
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