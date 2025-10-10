#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

void solve()
{
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    cout<<(A+B+C)*D<<'\n';
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