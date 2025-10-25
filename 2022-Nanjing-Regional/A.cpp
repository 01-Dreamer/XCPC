#include<bits/stdc++.h>

#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=1010;
map<char,PII>ops;
int s[N][N];

void insert(int x1,int y1,int x2,int y2,int v)
{
    s[x1][y1]+=v;
    s[x2+1][y1]-=v;
    s[x1][y2+1]-=v;
    s[x2+1][y2+1]+=v;
}

int get(int x1,int y1)
{
    return x1*1e4+y1;
}

void solve()
{
    int n,m,k;
    string op;
    cin>>n>>m>>k;
    cin>>op;

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            s[i][j]=0;
    
    int x1=1,y1=1,x2=n,y2=m;
    for(int i=op.size()-1;i>=0;i--)
    {
        int dx=-ops[op[i]].x,dy=-ops[op[i]].y;
        x1+=dx,y1+=dy;
        x2+=dx,y2+=dy;

        if((x1<1||x1>n||y1<1||y1>m)&&(x2<1||x2>n||y2<1||y2>m))
        {
            if(k==0) cout<<n*m<<'\n';
            else cout<<0<<'\n';
            return;
        }

        if(x1<1) x1=1;
        if(x1>n) x1=n;
        if(y1<1) y1=1;
        if(y1>m) y1=m;

        if(x2<1) x2=1;
        if(x2>n) x2=n;
        if(y2<1) y2=1;
        if(y2>m) y2=m;
    }
    int cnt=(x2-x1+1)*(y2-y1+1);

    set<int>st;
    st.insert(get(x1,y1));
    insert(x1,y1,x2,y2,1);
    for(int i=0;i<op.size();i++)
    {
        int dx=ops[op[i]].x,dy=ops[op[i]].y;
        x1+=dx,y1+=dy;
        x2+=dx,y2+=dy;

        if(x1<1) x1=1;
        if(x1>n) x1=n;
        if(y1<1) y1=1;
        if(y1>m) y1=m;

        if(x2<1) x2=1;
        if(x2>n) x2=n;
        if(y2<1) y2=1;
        if(y2>m) y2=m;

        if(st.count(get(x1,y1))) continue;
        st.insert(get(x1,y1));

        insert(x1,y1,x2,y2,1);
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]+=s[i-1][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]+=s[i][j-1];

    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(cnt-s[i][j]==k)
                res++;
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ops['U']={-1,0};
    ops['D']={1,0};
    ops['L']={0,-1};
    ops['R']={0,1};

    int T=1;
    cin>>T;
    while(T--) solve();
    

    return 0;
}
