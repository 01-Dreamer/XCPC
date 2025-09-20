#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int,int> PII;
string I,J,a,b,c,d,e,f;

PII get(const string& s)
{
    size_t pos1=s.find(",", 0);
    size_t pos2=s.find(",", pos1+1);
    return {pos1,pos2};
}

int getJ(int d,int e,int f)
{
    if(d==e) return 0;

    if(f>0)
    {
        if(d>=e) return 0;
        int k=(e-d+f-1)/f;
        int sum=k*d+(k*(k-1)/2)*f;
        return sum;
    }
    else
    {
        if(d<=e) return 0;
        int k=-(d-e-f-1)/f;
        int sum=k*d+(k*(k-1)/2)*f;
        return sum;
    }
}

void solve()
{
    string s;
    cin>>s>>s;
    cin>>I;
    cin>>s>>s;
    
    PII t=get(s);

    a=s.substr(6,t.first-6);
    if(t.second!=string::npos)
    {
        b=s.substr(t.first+1,t.second-t.first-1);
        size_t pos3=s.find(")", t.second+1);
        c=s.substr(t.second+1,pos3-t.second-1);
    }
    else
    {
        size_t pos3=s.find(")", t.second+1);
        b=s.substr(t.first+1,pos3-t.first-1);
        c="1";
    }

    cin>>s;
    cin>>J;
    cin>>s>>s;
    t=get(s);
    d=s.substr(6,t.first-6);
    if(t.second!=string::npos)
    {
        e=s.substr(t.first+1,t.second-t.first-1);
        size_t pos3=s.find(")", t.second+1);
        f=s.substr(t.second+1,pos3-t.second-1);
    }
    else
    {
        size_t pos3=s.find(")", t.second+1);
        e=s.substr(t.first+1,pos3-t.first-1);
        f="1";
    }
    cin>>s>>s;
    //cout<<I<<' '<<J<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<'\n';
    

    int ans=0;
    if(stoll(c)>0)
    {
        for(int i=stoll(a);i<stoll(b);i+=stoll(c))
        {
            int D,E,F;
            if(d==I) D=i;
            else D=stoll(d);
            if(e==I) E=i;
            else E=stoll(e);
            if(f==I) F=stoll(c);
            else F=stoll(f);

            ans+=getJ(D,E,F);
        }
    }
    else
    {
        for(int i=stoll(a);i>stoll(b);i+=stoll(c))
        {
            int D,E,F;
            if(d==I) D=i;
            else D=stoll(d);
            if(e==I) E=i;
            else E=stoll(e);
            if(f==I) F=stoll(c);
            else F=stoll(f);

            ans+=getJ(D,E,F);
        }
    }

    cout<<ans<<'\n';
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
