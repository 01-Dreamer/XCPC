#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef __int128_t int128;
typedef pair<int,int> PII;
int P,m;

void solve()
{
    cin>>P>>m;

    set<int>s;
    int cnt=0;
    for(int k=0;k<=100;k++)
    {
        int g=((int128)k*P+1)^((int128)P-1);
        if(g<=m) s.insert(g);
        cout<<k<<' '<<g<<'\n';

    }
    cout<<s.size()<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}