
#include <bits/stdc++.h>

using namespace std;
const int N=2010;
bitset<N> a[N];
int n,m,p;
int pos[N];
int B[N][N];

int gauss()
{
    memset(pos,-1,sizeof(pos));
    int r,c;
    for(r=c=0;c<m;c++)
    {
        int t=-1;
        for(int i=r;i<n;i++)
           if(a[i][c])
           {
               t=i;
               break;
           }
        if(t==-1) continue;
        swap(a[r],a[t]);
        pos[c]=r;
        for(int i=r+1;i<n;i++)
           if(a[i][c]) a[i]^=a[r];
        r++;
    }
    
    for(int i=r;i<n;i++)
       for(int j=m;j<m+p;j++)
          if(a[i][j]) return 1;

    static bitset<N> x[N];
    for(int i=0;i<m;i++) x[i].reset();

    for(int i=m-1;i>=0;i--)
    {
        if(pos[i]==-1) continue;
        bitset<N> rhs=a[pos[i]];
        for(int j=i+1;j<m;j++)
            if(pos[j]!=-1 && a[pos[i]][j]) rhs^=x[j];
        for(int t=0;t<m;t++) rhs[t]=0;
        x[i]=rhs;
    }

    for(int i=0;i<m;i++)
       for(int j=0;j<p;j++)
           B[i][j]=x[i][m+j];

    if(r<m) return 2;
    return 0;
}

int main()
{
    cin>>n>>m>>p;
    for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
       {
           int x;
           cin>>x;
           a[i][j]=x;
       }
    for(int i=0;i<n;i++)
      for(int j=0;j<p;j++)
      {
          int x;
          cin>>x;
          a[i][m+j]=x;
      }
          
    int t=gauss();
    if(t==1) puts("No");
    else
    {
        puts("Yes");
        for(int i=0;i<m;i++)
            for(int j=0;j<p;j++)
                cout<<B[i][j]<<(j==p-1?'\n':' ');
        
    }
          
    return 0;
}
