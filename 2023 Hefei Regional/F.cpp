#include <bits/stdc++.h>

#define x first
#define y second
#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    int n;
    map<string,int>cnt;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        cnt[s]++;
    }

    for(auto[k,v]:cnt)
        if(v*2>n)
        {
            cout<<k<<'\n';
            return;
        }
    
    cout<<"uh-oh"<<'\n';
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