#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
struct Node
{
    int l,r;
    vector<int>pos;
};

void solve()
{
    int n,m,k,w;
    cin>>n>>m>>k>>w;

    vector<int>a(n+m,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=n;i<n+m;i++) cin>>a[i],a[i]*=-1;
    sort(a.begin(),a.end(),[](int a,int b){
        return abs(a)<abs(b);
    });

    int l=1;
    vector<int>pos;
    vector<Node>v;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<0)
        {
            if(pos.empty())
            {
                l=abs(a[i])+1;
                continue;
            }
            v.push_back({l,abs(a[i])-1,pos});
            pos.clear();
            l=abs(a[i])+1;
        }
        else pos.push_back(a[i]);
    }
    if(pos.size()) v.push_back({l,w,pos});

    vector<int>ans;
    auto work=[&](Node& t){
        vector<PII>v;
        int R=-1;
        for(int i:t.pos)
        {
            if(i<=R) continue;
            v.push_back({i,i+k-1});
            R=i+k-1;
            if(R>t.r) break;
        }

        if(R>t.r)
        {
            int d=R-t.r;
            v.back().first-=d;
            v.back().second-=d;
            for(int i=v.size()-2;i>=0;i--)
            {
                d=v[i].second-v[i+1].first+1;
                if(d<=0)continue;
                v[i].first-=d;
                v[i].second-=d;
            }
            if(v.front().first<t.l) return false;
        }

        for(auto[x,y]:v) ans.push_back(x);
        return true;
    };

    for(Node& t:v)
        if(!work(t))
        {
            cout<<-1<<'\n';
            return;
        }

    cout<<ans.size()<<'\n';
    for(int i:ans) cout<<i<<' ';
    cout<<'\n';
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
