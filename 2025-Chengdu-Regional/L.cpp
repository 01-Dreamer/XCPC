#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10,M=N*2;
int h[N],e[M],ne[M],idx;
int a[N],b[N];
int sz[N],son[N];
int ans[N];
PII cnt[N];
int n;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs_son(int u,int father)
{
    sz[u]=1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        int t=dfs_son(j,u);
        if(sz[son[u]]<t) son[u]=j;
        sz[u]+=t;
    }
    return sz[u];
}

int needA,needB;
void update(int u,int father,int sign,int pson)
{
    int A=a[u],B=b[u];
    if(A>0)
    {
        if(cnt[A].x<cnt[A].y) needA-=cnt[A].y-cnt[A].x;
        else needB-=cnt[A].x-cnt[A].y;
        cnt[A].x+=sign;
        if(cnt[A].x<cnt[A].y) needA+=cnt[A].y-cnt[A].x;
        else needB+=cnt[A].x-cnt[A].y;
    }
    else cnt[A].x+=sign;;

    if(B>0)
    {
        if(cnt[B].x<cnt[B].y) needA-=cnt[B].y-cnt[B].x;
        else needB-=cnt[B].x-cnt[B].y;
        cnt[B].y+=sign;
        if(cnt[B].x<cnt[B].y) needA+=cnt[B].y-cnt[B].x;
        else needB+=cnt[B].x-cnt[B].y;
    }
    else cnt[B].y+=sign;

    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father||j==pson) continue;
        update(j,u,sign,pson);
    }
}

void dfs(int u,int father,int op)
{
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father||j==son[u]) continue;
        dfs(j,u,0);
    }
    if(son[u]) dfs(son[u],u,1);
    update(u,father,1,son[u]);
    ans[u]=cnt[0].x>=needA&&cnt[0].y>=needB;
    if(!op)
    {
        update(u,father,-1,0);
        needA=needB=0;
    }
}

void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        h[i]=-1;
        cnt[i]={0,0};
        sz[i]=0;
        son[i]=0;
    }
    needA=needB=0;
    idx=0;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs_son(1,-1);
    dfs(1,-1,1);

    for(int i=1;i<=n;i++) cout<<ans[i];
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