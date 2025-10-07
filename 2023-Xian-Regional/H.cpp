#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e7+10;
int cnt[N];
struct Node
{
    int power,pos;

    bool operator < (const Node& t) const
    {
        return power>t.power;
    }
}e[N];
int n,k;

void add(int pos)
{
    while(pos)
    {
        cnt[pos]++;
        pos>>=1;
    }
}

void solve()
{
    cin>>n>>k;
    for(int i=0;i<(1<<n);i++)
    {
        int power;
        cin>>power;
        e[i]={power,(1<<n)+i};
    }
    sort(e,e+((1<<n)));

    vector<int>res(1<<n,0);
    for(int i=0;i<(1<<n);i++)
    {
        int power=e[i].power;
        int pos=e[i].pos;
        int ans=0;

        if(power==2)
        {
            cout<<"Test";
        }
        while(true)
        {
            pos>>=1;
            if(!pos) break;
            if(cnt[pos]<=k&&(1<<n)-(1<<ans+1)-(i-cnt[pos])>=cnt[pos]) ans++;
            else break;
        }
        res[e[i].pos-(1<<n)]=ans;
        add(e[i].pos);
    }

    for(int i=0;i<(1<<n);i++) cout<<res[i]<<' ';
    cout<<'\n';
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
