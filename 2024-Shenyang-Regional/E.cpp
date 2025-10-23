#include<bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=16,M=1<<N;
int a[4];
int dist[M];
bool st[M];
vector<PII>ops;

int get(const string& st)
{
    int res=0,base=1;
    for(int i=3;i>=0;i--)
    {
        if(st[i]=='1') res+=base;
        base<<=1;
    }
    return res;
}

int get_pre(int x,int mask)
{
    int y=0;
    for(int i=0;i<N;i++)
        if(x>>i&1)
        {
            int st=i;
            st^=mask;
            y|=1<<st;
        }
    return y;
}

void init()
{
    // 单个
    ops.push_back({8, a[0]});
    ops.push_back({4, a[0]});
    ops.push_back({2, a[0]});
    ops.push_back({1, a[0]});
    // 行
    ops.push_back({12, a[1]});
    ops.push_back({3, a[1]});
    // 列
    ops.push_back({10, a[2]});
    ops.push_back({5, a[2]});
    // 整体
    ops.push_back({15, a[3]});

    memset(dist,0x3f,sizeof dist);
    dist[0]=0;

    priority_queue<PII,vector<PII>,greater<>>q;
    q.push({0,0});
    while(!q.empty())
    {
        PII t=q.top();
        q.pop();
        int ds=t.first,ver=t.second;
        if(st[ver]) continue;
        st[ver]=true;
        for(auto& op:ops)
        {
            int mask=op.first;
            int cost=op.second;
            int j=get_pre(ver,mask);
            if(dist[j]>dist[ver]+cost)
            {
                dist[j]=dist[ver]+cost;
                q.push({dist[j],j});
            }
            j|=1<<(15^mask);
            if(dist[j]>dist[ver]+cost)
            {
                dist[j]=dist[ver]+cost;
                q.push({dist[j],j});
            }
        }
    }
}

void solve()
{
    int m;
    cin>>m;
    int x=0;
    while(m--)
    {
        string st;
        string s;
        cin>>s,st+=s;
        cin>>s,st+=s;
        x|=1<<get(st);
    }
    cout<<dist[x]<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T>>a[0]>>a[1]>>a[2]>>a[3];
    init();
    while(T--) solve();

    return 0;
}
