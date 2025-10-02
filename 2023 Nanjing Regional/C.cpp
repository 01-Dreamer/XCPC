#include <bits/stdc++.h>

#define x first
#define y second
#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;

// 将 [l,r] 分解为幂二对齐区间 (b, k) => 区间 [b, b+2^k-1]
vector<PII> get(int l,int r)
{
    vector<PII> res;
    int cur=l;
    while(cur<=r)
    {
        int k=63-__builtin_clzll(r-cur+1);
        while(k>0)
        {
            if((cur&((1LL<<k)-1))==0) break;
            k--;
        }
        res.push_back({cur,k});
        cur+=1LL<<k;
    }
    return res;
}

vector<PII> xorIntervals(int l,int r,int x)
{
    vector<PII> blocks=get(l,r);
    vector<PII> intervals;

    for(auto[b,k]:blocks)
    {
        int len=1LL<<k;
        int L=(b^x)&(~(len-1));
        intervals.push_back({L,L+len-1});
    }
    sort(intervals.begin(),intervals.end());
    
    vector<PII> res;
    int L = intervals[0].x,R=intervals[0].y;
    for(int i=1;i<intervals.size();i++)
        if(intervals[i].x<=R+1) R=max(R,intervals[i].y);
        else
        {
            res.push_back({L,R});
            L=intervals[i].x;
            R=intervals[i].y;
        }
    res.push_back({L,R});
    return res;
}

void solve()
{
    int P,m;
    cin>>P>>m;

    auto t=xorIntervals(0,m,P-1);
    int res=0;
    for(auto[x,y]:t)
    {
        int l=x,r=y;
        if(r<1) continue;
        int L=(l-2)/P;
        int R=(r-1)/P;
        if(l<2) L=-1;
        res+=R-L;
    }
    cout<<res<<'\n';
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