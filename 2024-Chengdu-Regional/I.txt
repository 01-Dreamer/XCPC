#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10;
struct Node
{
    int l,r;
    int d;
}tr[N*4];
int w[N],g[N];
int num[N];
int n,q;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

void pushup(int u)
{
    tr[u].d=gcd(tr[u<<1].d,tr[u<<1|1].d);
}

void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,r,g[r]};
    else
    {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int x,int v)
{
    if(tr[u].l==tr[u].r) tr[u].d=v;
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

int query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r) return tr[u].d;
    int res=0;
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) res=gcd(res,query(u<<1,l,r));
    if(r>mid) res=gcd(res,query(u<<1|1,l,r));
    return res;
}

void getNum()
{
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            num[j]++;
}

int getNum(int x)
{
    if(!x) return n;
    return num[x];
}

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n*4;i++) tr[i]={0,0,0},g[i]=0;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i+1<=n;i++)
        if(w[i]>w[i+1]) g[i]=i;
        else g[i]=0;
    
    build(1,1,n);
    cout<<getNum(query(1,1,n))<<'\n';
    while(q--)
    {
        int x,v;
        cin>>x>>v;
        w[x]=v;
        if(x+1<=n)
        {
            if(w[x]>w[x+1]) g[x]=x;
            else g[x]=0;
            modify(1,x,g[x]);
        }
        if(x-1>=1)
        {
            if(w[x-1]>w[x]) g[x-1]=x-1;
            else g[x-1]=0;
            modify(1,x-1,g[x-1]);
        }
        cout<<getNum(query(1,1,n))<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getNum();

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
