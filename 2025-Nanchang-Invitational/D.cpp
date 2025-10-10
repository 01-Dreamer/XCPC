#include <bits/stdc++.h>

#define x first
#define y second
#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
PII a[N],b[N],c[N];
int n,A,B,C;

int get(PII a[])
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(a[i].x);
        v.push_back(a[i].y);
        v.push_back(a[i].y+1);
    }
    v.push_back(A);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    map<int,int>m;
    for(int i=0;i<v.size();i++) m[v[i]]=i+1;

    vector<int>d(v.size()+10,0);
    for(int i=0;i<n;i++)
    {
        int l=m[a[i].x],r=m[a[i].y];
        if(l>r) swap(l,r);
        d[l]++,d[r+1]--;
    }

    for(int i=1;i<d.size();i++) d[i]+=d[i-1];

    int res=0;
    for(int i=1;i<d.size();i++) res=max(res,d[i]);
    return res;
}


void solve()
{
    cin>>n>>A>>B>>C;
    for(int i=0;i<n;i++)
        cin>>a[i].x>>b[i].x>>c[i].x>>a[i].y>>b[i].y>>c[i].y;
    
    cout<<max(max(get(a),get(b)),get(c))<<'\n';
    
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