#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++) cout<<1;
    for(int i=0;i<n-k;i++) cout<<4;
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    while(T--) solve();

    return 0;
}