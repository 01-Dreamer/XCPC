#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=2e5+10;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<bool>f(k+1,false);
    vector<int>a(m,0),b(m,0);

    int p=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        f[x]=true;
        if(!p) p=x;
    }

    int res=0;
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]==b[i]) b[i]=p;
        if(a[i]>b[i]) swap(a[i],b[i]);
        if(f[a[i]]&&f[b[i]]) res++;
    }

    vector<int>cnt(k+1,0);
    for(int i=0;i<m;i++)
        if(f[a[i]]+f[b[i]]==1)
            if(f[a[i]]) cnt[b[i]]++;
            else cnt[a[i]]++;

    int mx1=0,mx2=0;
    for(int i=1;i<=k;i++)
        if(cnt[i]>=mx1) mx2=mx1,mx1=cnt[i];
        else if(cnt[i]>mx2) mx2=cnt[i];

    map<PII,int>tot;
    for(int i=0;i<m;i++)
        if(!f[a[i]]&&!f[b[i]])
            tot[{a[i],b[i]}]++;

    int maxv=0;
    for(auto[key,val]:tot)
        maxv=max(maxv,cnt[key.first]+cnt[key.second]+val);

    res+=max(mx1+mx2,maxv);
    cout<<res<<'\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
