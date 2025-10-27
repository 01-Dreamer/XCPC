#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2010;
int a[N][N];
bool st[N];
vector<int>v[N];
int n;

// a[u][v]=a[1][u]^a[1][v]^lca(u,v);
int lca(int u,int v)
{
    if(u>v) swap(u,v);
    return a[u][v]^a[1][u]^a[1][v];
}

bool check(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(i==u) continue;
        if(st[i]) continue;
        if(lca(u,i)==u) return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            cin>>a[i][j];
    
    int cnt=n,layer=0;
    while(cnt)
    {
        layer++;
        for(int i=1;i<=n;i++)
            if(!st[i]&&check(i))
            {
                v[layer].push_back(i);
                st[i]=true;
                cnt--;
            }
    }

    // for(int i=1;i<=layer;i++)
    // {
    //     for(int u:v[i])
    //         cout<<u<<' ';
    //     cout<<'\n';
    // }

    for(int i=1;i+1<=layer;i++)
        for(int u:v[i])
        {
            for(int j=i+1;j<=layer;j++)
            {
                bool success=false;
                for(int fa:v[j])
                    if(lca(u,fa)==fa)
                    {
                        cout<<u<<' '<<fa<<'\n';
                        success=true;
                        break;
                    }
                if(success) break;
            }
        }
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
