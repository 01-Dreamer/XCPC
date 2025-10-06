#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
ld x[N],y[N];
int n,a,b,c;

ld get_dist(ld x1,ld y1,ld x2,ld y2)
{
    ld dx=x1-x2;
    ld dy=y1-y2;
    return sqrt(dx*dx+dy*dy);
}

ld get_min(ld X,ld Y)
{
    ld maxv=-1e18;
    for(int i=0;i<n;i++)
    {
        ld ds=get_dist(X,Y,x[i],y[i]);
        maxv=max(maxv,ds);
    }
    return maxv;
}

ld f(ld X)
{
    if(b) return get_min(X,-(ld)a/b*X-(ld)c/b);
    else return get_min(-c/(ld)a,X);
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    cin>>a>>b>>c;

    ld l=-1e18,r=1e18;
    ld f1,f2;
    while(r-l>1e-9)
    {
        ld lmid=l+(r-l)/3;
        ld rmid=r-(r-l)/3;
        f1=f(lmid),f2=f(rmid);

        if(f1<=f2) r=rmid;
        else l=lmid;
    }
    cout<<fixed<<setprecision(12);
    cout<<min(f1,f2)<<'\n';
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