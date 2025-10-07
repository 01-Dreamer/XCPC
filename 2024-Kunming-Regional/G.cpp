#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=5010;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int bfs(int a,int b)
{
    queue<pair<PII,int>>q;
    q.push({{a,b},0});

    int res=1e9;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();

        int x=t.first.first,y=t.first.second,cnt=t.second;
        if(cnt>25) continue;
        if(x==0||y==0)
        {
            res=min(res,cnt);
            continue;
        }

        int g=gcd(x,y);
        if(x) q.push({{x-g,y},cnt+1});
        if(y) q.push({{x,y-g},cnt+1});
    }

    return res+1;
}


void solve()
{
    map<int,int>m[N];

    int a,b;
    cin>>a>>b;
    cout<<bfs(a,b)<<'\n';
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
