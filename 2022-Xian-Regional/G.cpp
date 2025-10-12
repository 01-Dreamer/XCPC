#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int tr[N][26],cnt[N],idx;
vector<string>s;

void insert(const string& str)
{
    int p=0;
    for(int i=0;i<str.size();i++)
    {
        int t=str[i]-'a';
        if(!tr[p][t]) tr[p][t]=++idx;
        p=tr[p][t];
    }
    cnt[p]++;
}

void del(const string& str)
{
    int p=0;
    for(int i=0;i<str.size();i++)
    {
        int t=str[i]-'a';
        p=tr[p][t];
    }
    cnt[p]--;
}

int query(const string& str,int pos)
{
    int p=0;
    for(int i=pos;i<str.size();i++)
    {
        int t=str[i]-'a';
        if(!tr[p][t]) return -1;
        if(!cnt[tr[p][t]]) return -1;
        p=tr[p][t];
    }
    return cnt[p];
}


void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str.size()>=500) continue;
        s.push_back(str);
        insert(str);
    }

    sort(s.begin(),s.end(),[](const string& s1,const string& s2){
    return s1.size()>s2.size();});

    for(int i=0;i<s.size();i++)
    {
        string& str=s[i];
        bool success=true;
        for(int j=0;j<str.size();j++)
            if(query(s[i],j)==-1)
            {
                success=false;
                break;
            }
        if(!success) continue;
        cout<<str.size()<<'\n';
        return;
    }
    
    cout<<0<<'\n';
    
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