#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=3e5+10;
set<int>e[N];
int p[N];
bool st[N];
int n,m;

stack<int>stk;
vector<PII>ans;
bool dfs(int v)
{
    int u=stk.top();
    vector<int>del;
    for(int V:e[u])
        if(st[V]) del.push_back(V);
    for(int V:del)
        e[u].erase(V);

    if(e[u].empty())
    {
        if(stk.size()<=1) return false;
        stk.pop();
        return dfs(v);
    }
    if(e[u].find(v)!=e[u].end())
    {
        stk.push(v);
        st[v]=true;
        return true;
    }

    ans.push_back({u,v});
    stk.push(v);
    st[v]=true;
    return true;
}

void solve()
{
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        e[a].insert(b);
        e[b].insert(a);
    }
    for(int i=1;i<=n;i++) cin>>p[i];

    stk.push(p[1]);
    st[p[1]]=true;
    for(int i=2;i<=n;i++)
        if(!dfs(p[i]))
        {
            while(!stk.empty()) stk.pop();
            stk.push(p[i]);
            st[p[i]]=true;
        }

    cout<<ans.size()<<'\n';
    for(auto[x,y]:ans) cout<<x<<' '<<y<<'\n';
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