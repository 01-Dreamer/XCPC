#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<100<<'\n';
    for(int i=0;i<50;i++) cout<<a<<' ';
    for(int i=50;i<95;i++) cout<<b<<' ';
    for(int i=95;i<99;i++) cout<<c<<' ';
    cout<<c+1<<'\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    //cin>>T;
    while(T--) solve();

    return 0;
}
