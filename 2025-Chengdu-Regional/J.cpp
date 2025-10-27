#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int a[N],b[N]; // 申诉前、申诉后

int get(int x)
{
    if(x>=1) x--;
    else x++;
    return x;
}

void solve()
{
    int n,m,k,B;
    cin>>n>>m>>k>>B;
    for(int i=0;i<n;i++)
    {
        a[i]=b[i]=0;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            a[i]+=x;
            b[i]+=get(x);
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
        if(a[i]>=k) res++;
        else if(B&&b[i]>=k) res++,B--;
    cout<<res<<'\n';
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