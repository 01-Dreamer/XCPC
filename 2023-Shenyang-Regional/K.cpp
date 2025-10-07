#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef long long LL;
const int N=1e6+10;
int tr_sum[N],tr_cnt[N];
int w[N];
int n,q;

int lowbit(int x)
{
    return x&-x;
}

int sz;
void add(int x,int v,int tr[])
{
    for(int i=x;i<=sz;i+=lowbit(i)) tr[i]+=v;
}

int query(int x,int tr[])
{
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i)) sum+=tr[i];
    return sum;
}

struct Query
{
    int x,v;
}Q[N];

vector<int>v;
map<int,int>m;


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;

    int sum=0;
    map<int,int>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        if(w[i]>0)
        {
            v.push_back(w[i]);
            cnt[w[i]]++;
        }
        else sum+=-w[i];
    }

    for(int i=0;i<q;i++)
    {
        cin>>Q[i].x>>Q[i].v;
        if(Q[i].v>0) v.push_back(Q[i].v);
    }

    if(v.empty())
    {
        for(int i=0;i<q;i++) cout<<1<<'\n';
        return 0;
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++) m[v[i]]=i+1;
    sz=v.size();

    for(auto[k,v]:cnt)
    {
        add(m[k],v,tr_cnt);
        add(m[k],k*v,tr_sum);
    }

    auto check=[&](int mid)
    {
        return query(mid,tr_sum)>=sum;
    };

    for(int i=0;i<q;i++)
    {
        int x=Q[i].x,v=Q[i].v;
        if(w[x]>0)
        {
            add(m[w[x]],-1,tr_cnt);
            add(m[w[x]],-w[x],tr_sum);
        }
        else sum-=-w[x];
        if(v>0)
        {
            add(m[v],1,tr_cnt);
            add(m[v],v,tr_sum);
        }
        else sum+=-v;
        w[x]=v;

        if(query(sz,tr_sum)<=sum)
        {
            cout<<query(sz,tr_cnt)+1<<'\n';
            continue;
        }

        int l=0,r=sz;
        while(l<r)
        {
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(!r)
        {
            cout<<1<<'\n';
            continue;
        }
        
        int maxv=query(sz,tr_cnt);
        int minv=maxv-query(r-1,tr_cnt);
        int d=sum-query(r-1,tr_sum);
        int tot=d/r;
        minv-=tot;
        cout<<maxv-minv+1<<'\n';
    }

    return 0;
}
