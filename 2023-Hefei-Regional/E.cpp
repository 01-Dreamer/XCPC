#include <bits/stdc++.h>


#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;


void solve()
{
    int n,m;
    map<int,vector<int>>si,sj;

    cin>>n>>m;
    vector<vector<int>>g(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x=g[i][j];
            if(si[x].empty()) si[x].push_back(0);
            si[x].push_back(i);
        }

    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
        {
            int x=g[i][j];
            if(sj[x].empty()) sj[x].push_back(0);
            sj[x].push_back(j);
        }
        
    for(auto&[k,v]:si)
        for(int i=1;i<v.size();i++)
            v[i]+=v[i-1];
    for(auto&[k,v]:sj)
        for(int i=1;i<v.size();i++)
            v[i]+=v[i-1];

    int res=0;
    for(auto&[k,v]:si)
        for(int i=1;i<v.size();i++)
        {
            int val=v[i]-v[i-1];
            int Lcnt=i-1,Rcnt=v.size()-i-1;
            int Lsum=v[i-1],Rsum=v[v.size()-1]-v[i];
            res+=val*Lcnt-Lsum;
            res+=Rsum-val*Rcnt;
        }

    for(auto&[k,v]:sj)
        for(int i=1;i<v.size();i++)
        {
            int val=v[i]-v[i-1];
            int Lcnt=i-1,Rcnt=v.size()-i-1;
            int Lsum=v[i-1],Rsum=v[v.size()-1]-v[i];
            res+=val*Lcnt-Lsum;
            res+=Rsum-val*Rcnt;
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