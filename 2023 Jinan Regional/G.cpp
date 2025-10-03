#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10,MOD=1e9+7;
int p[N*2];
vector<string>g;
int n,m;

int qmi(int a,int n)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return res;
}

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void solve()
{
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++) cin>>g[i];
    for(int i=0;i<n*2;i++) p[i]=i;
    if(m&1)
    {
        int cnt=0;
        for(int i=0;i<n;i++) cnt+=g[i][(m-1)/2]=='1';
        if(cnt>=2)
        {
            cout<<"0"<<'\n';
            return;
        }
    }

    for(int j=0;j<m;j++)
    {
        int l=j,r=m-j-1;
        vector<int>lpos,rpos;
        for(int i=0;i<n;i++)
        {
            if(g[i][l]=='1') lpos.push_back(i);
            if(g[i][r]=='1') rpos.push_back(i);
            if(lpos.size()+rpos.size()>=3)
            {
                cout<<"0"<<'\n';
                return;
            }
        }
        if(lpos.size()+rpos.size()==2)
        {
            if(lpos.size()==2)
            {
                int u=lpos[0],v=lpos[1];
                p[find(u)]=find(v+n);
                p[find(v)]=find(u+n);
            }
            else if(rpos.size()==2)
            {
                int u=rpos[0],v=rpos[1];
                p[find(u)]=find(v+n);
                p[find(v)]=find(u+n);
            }
            else
            {
                int u=lpos[0],v=rpos[0];
                if(u==v) continue;
                p[find(u)]=find(v);
                p[find(u+n)]=find(v+n);
            }
        }
    }

    for(int i=0;i<n;i++)
        if(find(i)==find(i+n))
        {
            cout<<"0"<<'\n';
            return;
        }

    set<int>s;
    for(int i=0;i<n*2;i++) s.insert(find(i));
    cout<<qmi(2,s.size()/2)<<'\n';
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