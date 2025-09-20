#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int> v;
void divide(int x)
{
    for(int i=2;i<=x/i;i++)
       if(x%i==0)
       {
           int s=0;
           while(x%i==0) x/=i,s++;
           v.push_back(s);
       }
    if(x>1) v.push_back(1);
}

void solve()
{
    v.clear();

    int n;
    cin>>n;
    divide(n);

    int res=1;
    for(int i=1;i<(1<<v.size());i++)
    {
        int sum=1,cnt=0;
        for(int j=0;j<v.size();j++)
            if(i>>j&1)
            {
                sum*=v[j];
                cnt++;
            }
        res+=sum*(1<<(cnt-1));
    }
    cout<<res<<'\n';
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
