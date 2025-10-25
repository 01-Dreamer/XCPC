#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10;
int a[N];
int n,k,m,c,d;

bool check(int mid)
{
    int cnt=0;
    vector<bool>f(n+1,false);
    vector<int>val(n+1,0);
    for(int i=1;i<=n;i++)
    {
        f[i]=a[i]>=mid;
        cnt+=a[i]>=mid;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]) continue;
        int D=mid-a[i]-c;
        int j;
        if(D<=0) j=0;
        else if(!d) j=m;
        else j=(D+d-1)/d;
        if(j<m)
        {
            int l=max(1LL,i-m+1);
            int r=min(n-m+1,i-j);
            if(l>r) continue;
            val[l]++,val[r+1]--;
        }
    }
    int maxv=0;
    for(int i=1;i<=n-m+1;i++)
    {
        val[i]+=val[i-1];
        maxv=max(maxv,val[i]);
    }
    return cnt+maxv>=k;
}

void solve()
{
    cin>>n>>k>>m>>c>>d;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=0,r=1e15;
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

    int T=1;
    //cin>>T;
    while(T--) solve();
    

    return 0;
}
