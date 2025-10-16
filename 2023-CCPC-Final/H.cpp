#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=2e6+10;
int n;

void solve()
{
    cin>>n;
    set<int>s;
    for(int i=1;i<=n*2;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    if(s.size()<=n) cout<<"Qingyu"<<'\n';
    else cout<<"Kevin"<<'\n';
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