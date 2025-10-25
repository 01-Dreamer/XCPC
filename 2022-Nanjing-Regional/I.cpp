#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    string s;
    cin>>s;
    map<char,int>cnt;
    for(char c:s) cnt[c]++;
    int maxv=-1;
    for(auto&[key,val]:cnt) maxv=max(maxv,val);
    cout<<s.size()-maxv<<'\n';
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
