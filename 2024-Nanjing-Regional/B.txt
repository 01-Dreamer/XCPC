#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve()
{
    string s;
    cin>>s;
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<s.size();i++)
        if(i&1)
        {
            if(s[i]=='0') s[i]++,cnt1++;
            else if(s[i]=='1') s[i]--,cnt0++;
            else cnt2++;
        }
        else
        {
            if(s[i]=='0') cnt0++;
            else if(s[i]=='1') cnt1++;
            else cnt2++;
        }
    if(cnt0<cnt1) while(cnt0<cnt1&&cnt2>0) cnt0++,cnt2--;
    if(cnt0>cnt1) while(cnt0>cnt1&&cnt2>0) cnt1++,cnt2--;
    if(!cnt2) cout<<abs(cnt0-cnt1)<<'\n';
    else cout<<(cnt2&1)<<'\n';
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
