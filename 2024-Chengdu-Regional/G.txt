#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];

    set<int>s;
    s.insert(0);
    for(int i=0;i<n-1;i++)
    {
        int x=v[i],y=v[i+1];
        s.insert(x);
        s.insert(y);
        s.insert(x&y);
        s.insert(x|y);
        s.insert(x^y);
        s.insert(x&(x^y));
        s.insert(y&(x^y));
    }
    cout<<s.size()<<'\n';
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