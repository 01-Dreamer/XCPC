#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10,MOD=998244353;
int fact[N],infact[N];

int qmi(int a,int n)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return res;
}

void init()
{
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=(infact[i-1]*qmi(i,MOD-2))%MOD;
    }
}

int C(int n,int m)
{
    return fact[n]*infact[m]%MOD*infact[n-m]%MOD;
}

void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    s='@'+s;
    vector<int>S(n+1,0);
    for(int i=1;i<=n;i++) S[i]=S[i-1]+(s[i]=='1');

    int res=S[n]>=k;
    int lastL=-1,lastR=-1;
    for(int i=1,j=1;j<=n;j++)
    {
        while(i<j&&S[j]-S[i-1]>k) i++;
        if(S[j]-S[i-1]==k)
        {
            res=(res+C(j-i+1,k)-1+MOD)%MOD;
            if(lastL!=-1)
            {
                int l=max(lastL,i),r=min(lastR,j);
                if(l<r) res=(res-C(r-l+1,S[r]-S[l-1])+1+MOD)%MOD;
            }
            lastL=i,lastR=j;
        }
    }
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}

