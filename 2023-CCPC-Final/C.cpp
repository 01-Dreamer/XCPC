#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10,M=N*4;
int h[N],e[M],ne[M],idx;
int color[N];
int n,m;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void bfs()
{
    queue<int>q;
    q.push(1);
    color[1]=1;

    while(!q.empty())
    {
        int t=q.front();
        int c=color[t];
        q.pop();
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(color[j]) continue;
            color[j]=3-c;
            q.push(j);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<=n-1;i++)
    {
        h[i]=-1;
        color[i]=0;
    }
    idx=0;
    for(int i=1;i<=n-1;i++)
    {
        add(i,(i+1)%n);
        add((i+1)%n,i);
    }

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    bfs();
    for(int i=0;i<=n-1;i++)
        if(color[i]==1) cout<<'B';
        else cout<<'R';
    cout<<'\n';

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