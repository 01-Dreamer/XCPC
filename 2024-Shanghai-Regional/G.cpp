#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int a[N],b[N],c[N];
int n;

bool check(int mid)
{
    int cnt=0;
    vector<int> L,R;
    for(int i=0;i<n;i++)
        if(!a[i])cnt+=(b[i]>=mid);
        else
        {
            ld d=(ld)(mid-b[i])/a[i];
            if(a[i]>0) L.push_back(ceil(d));
            else R.push_back(floor(d));
        }

    sort(R.begin(),R.end());
    sort(L.begin(),L.end(),greater<int>());

    int l=0,r=n-1;
    for(int val:R)
        if(l<=r&&c[l]<=val)
            cnt++,l++;

    for(int val:L)
        if(l<=r&&c[r]>=val)
            cnt++,r--;

    return cnt>=(n+1)/2;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    sort(c,c+n);

    int l=-2e18,r=2e18;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<r<<'\n';
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