#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;

void solve()
{
    string s;
    cin>>s;

    if(s.size()&1)
    {
        cout<<"No"<<'\n';
        return;
    }

    stack<int>stk;
    for(int i=0;i<s.size();i++)
    {
        if(stk.empty()) stk.push(i);
        else
        {
            if(s[i]=='('||s[i]==')')
            {
                if(s[stk.top()]=='('||s[stk.top()]==')')
                {
                    s[stk.top()]='(';
                    s[i]=')';
                    stk.pop();
                    continue;
                }
            }
            else
            {
                if(s[stk.top()]=='['||s[stk.top()]==']')
                {
                    s[stk.top()]='[';
                    s[i]=']';
                    stk.pop();
                    continue;
                }
            }
            stk.push(i);
        }
    }

    if(!stk.empty())
    {
        cout<<"No"<<'\n';
        return;
    }
    
    for(int i=0;i<s.size()-1;i++)
    {
        bool flag=false;
        if(s[i]==s[i+1]) flag=true;
        if(s[i]==')'&&s[i+1]=='(') flag=true;
        if(s[i]==']'&&s[i+1]=='[') flag=true;
        if(flag)
        {
            cout<<"No"<<'\n';
            return;
        }
    }

    int fa=0;
    vector<int>p(s.size(),-1);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||s[i]=='[')
        {
            stk.push(i);
            p[i]=++fa;
        }
        else
        {
            p[stk.top()]=--fa;
            stk.pop();
        }
    }

    set<int>st1,st2;
    for(int i=0;i<s.size();i++)
        if(s[i]=='(')
        {
            if(st1.count(p[i]))
            {
                cout<<"No"<<'\n';
                return;
            }
            st1.insert(p[i]);
        }
        else if(s[i]=='[')
        {
            if(st2.count(p[i]))
            {
                cout<<"No"<<'\n';
                return;
            }
            st2.insert(p[i]);
        }

    cout<<"Yes"<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}