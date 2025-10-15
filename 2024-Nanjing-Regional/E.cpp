#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;

    k=min(k,n-1);
    s=' '+s+s.substr(0,k);

    vector<bool>st(s.size(),false);
    int last=0;
    while(true)
    {
        int p=s.find("nanjing",last);
        if(p!=string::npos)
        {
            st[p+6]=true;
            last=p+1;
        }
        else break;
    }

    int res=0;
    int cnt=0;
    for(int l=0,r=0;r<s.size();r++)
    {
        if(st[r]) cnt++;
        while(l<r&&r-l+1>n)
        {
            if(st[l]) cnt--;
            l++;
        }
        res=max(res,cnt);
    }

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
