#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;

    int res=1e18;
    for(int t=0;t<60;t++)
    {
        int sum=t*a;
        int tot=1LL<<t;
        sum+=(c+tot-1)/tot*b;
        res=min(res,sum);
    }
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