#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;


void solve()
{
    int n,k,m;
    cin>>n>>k>>m;
    int cnt=n/k; // k的倍数个数(不包含k)
    int tot=min(m,n-cnt); // k的个数
    m-=tot;
    if(m>0)
    {
        int d=min(m,cnt);
        cnt-=d;
        tot+=d;
    }
    if(cnt>=1) cnt--,tot++;
    cout<<cnt/2+tot<<'\n';
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