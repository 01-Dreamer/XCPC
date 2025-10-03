#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=110;
int p[N];
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    vector<PII>ans;
    for(int i=1;i<=n;i++)
    {
        if(i==p[i]) continue;
        int j=n;
        while(p[j]>p[i]) j--;
        sort(p+i,p+j+1);
        ans.push_back({i,j});
    }

    cout<<ans.size()<<'\n';
    for(auto[x,y]:ans) cout<<x<<' '<<y<<'\n'; 
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