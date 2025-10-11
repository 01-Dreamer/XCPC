#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
typedef unsigned long long ULL;
const int N=3e5+10,M=100000007;
int cnt[M];
array<int,26> S[N];
ULL H[N];
int n,k,q,len;
string s;

ULL h(ULL x)
{
    return x*x*x*14541*10086999;
}

ULL f(ULL x)
{
    return h(x&(1<<31)-1)+h(x>>31);
}

int get(int i)
{
    return i/len;
}

struct Query
{
    int l,r,id;
    bool operator <(const Query& t) const
    {
        int pos1=get(l),pos2=get(t.l);
        if(pos1!=pos2) return pos1<pos2;
        return r<t.r;
    }
}Q[N];
int ans[N];

int res;
void add(int x)
{
    ULL t=H[x];
    res+=cnt[t];
    cnt[t]++;
}

void del(int x)
{
    ULL t=H[x];
    cnt[t]--;
    res-=cnt[t];
}


void solve()
{
    cin>>n>>k>>q>>s;
    s='@'+s;
    len=sqrt(n);

    for(int c=0;c<26;c++)
        for(int i=1;i<=n;i++)
            S[i][c]=(S[i-1][c]+(s[i]==c+'a'))%k;
    
    for(int i=0;i<=n;i++)
        for(int c=0;c<26;c++)
            H[i]=H[i]*13331+f(S[i][c]+1e9+7);

    int idx=0;
    map<ULL,int>mp;
    set<int>st;
    for(int i=0;i<=n;i++)
    {
        if(mp.count(H[i])) H[i]=mp[H[i]];
        else
        {
            int t=idx++;
            mp[H[i]]=t;
            H[i]=t;
            st.insert(t);
        }
    }


    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        Q[i]={l-1,r,i};
    }


    sort(Q,Q+q);
    int L=1,R=1;
    add(1);
    for(int i=0;i<q;i++)
    {
        int l=Q[i].l,r=Q[i].r,id=Q[i].id;
        while(L<l) del(L++);
        while(L>l) add(--L);
        while(R<r) add(++R);
        while(R>r) del(R--);
        ans[id]=res;
    }

    for(int i=0;i<q;i++) cout<<ans[i]<<'\n';
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