#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
const int N=1010;
int h[N],e[N],ne[N],idx;
int cnt[N];
int n;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void solve()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
        cnt[u]++,cnt[v]++;
    }
    
    if(n==2)
    {
        cout<<"Bob"<<'\n';
        return;
    }

    int tot=0;
    for(int i=1;i<=n;i++) tot+=cnt[i]==1;
    
    if((n-tot-1)&1) cout<<"Alice"<<'\n';
    else cout<<"Bob"<<'\n';
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