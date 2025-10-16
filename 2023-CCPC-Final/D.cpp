#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int a[N],b[N];
int n,m;

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    int cnt=0;
    for(int i=0,j=0;i<n&&j<m;j++)
    {
        while(i<n&&a[i]!=b[j]) i++;
        if(i<n&&a[i]==b[j]) cnt++,i++;
    }

    if(cnt==m) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
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