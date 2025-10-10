#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
map<int,int>s;

int get(int i)
{
    int cnt=0;
    for(int j=1;j<=3;j++) cnt+=s[(i+j)%4]*j;
    int num=(cnt+i)%4;
    if(num) cnt+=4-num;
    return cnt;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s[x]++;
    }

    cout<<min(min(get(0),get(1)),min(get(2),get(3)))<<'\n';
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