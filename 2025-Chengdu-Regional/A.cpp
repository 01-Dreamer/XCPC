#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int,int> PII;
using ld=long double;
const int N=2e5+10;
int d[N],b[N],l[N],r[N];
int n;

bool check(int m)
{
    int M=m;
    for(int i=0;i<n;i++)
    {
        l[i]=(M*max(10*d[i]-5,0LL)+999)/1000;
        r[i]=(M*(10*d[i]+5)-1)/1000;
        b[i]=l[i];
        m-=b[i];
        if(l[i]>r[i]||m<0) return false;
    }
    for(int i=0;i<n;i++)
    {
        int D=min(r[i]-b[i],m);
        b[i]+=D;
        m-=D;
    }
    if(m) return false;
    return true;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>d[i];
    for(int m=1;m<=400;m++)
        if(check(m))
        {
            cout<<"Yes"<<'\n';
            for(int i=0;i<n;i++) cout<<b[i]<<' ';
            cout<<'\n';
            return;
        }
    cout<<"No"<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}