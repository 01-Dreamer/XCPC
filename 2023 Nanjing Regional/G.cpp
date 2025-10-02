#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=5010;
struct Node
{
    int v,w;
    bool operator <(const Node &t) const
    {
        return v>t.v;
    }
}e[N];
int n,m,k;

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>e[i].v>>e[i].w;
    sort(e+1,e+n+1);

    vector<int> maxW(n+1,0);
    vector<int> f(m+1,0);
    priority_queue<int,vector<int>,greater<int>> q;
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        q.push(e[i].w);
        sum+=e[i].w;
    }
    maxW[k]=sum;
    for(int i=k+1;i<=n;i++)
    {
        if(!q.empty()&&e[i].w>q.top())
        {
            sum+=e[i].w-q.top();
            q.pop();
            q.push(e[i].w);
        }
        maxW[i]=sum;
    }
    int res=maxW[n];
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=e[i].v;j--)
            f[j]=max(f[j],f[j-e[i].v]+e[i].w);
        res=max(res,f[m]+maxW[i-1]);
    }
    cout<<res<<'\n';
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