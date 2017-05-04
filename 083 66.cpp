#include <iostream>
using namespace std;

int bit(int a,int b)
{
    if((a & (1<<(b-1)))==0 ) return 0;
    return 1;
}

int Square(int a,int b, int m)
{
    for(int i=1; i<=m-1; i++)
    {
        if(bit(a,i)==bit(a,i+1)&& bit(a,i+1)==bit(b,i) && bit(b,i)==bit(b,i+1)) return 1;
    }
    return 0;
}

int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    
    int n,m;
    cin>>n>>m;
    if(n<m) swap(n,m);
    
    
    __int64 d[64][64];
    memset(d,0,64*64*4);

    int m2=1;
    for(int i=0; i<m; i++)
    {
        m2*=2;
    }

    for(int i=0; i<m2; i++)
    {
        for(int j=i; j<m2; j++)
        {
            if(Square(i,j,m)==0)
            {
                d[i][j]=1;
                d[j][i]=1;
            }
            
        }
    }

    __int64 a[30][64];
    memset(a,0,30*64*4);
    for(int i=0; i<m2; i++)
    {
        a[1][i]=1;
    }
    for(int i=2; i<=n+1; i++)
    {
        for(int j=0; j<m2; j++)
        {
            for(int k=0; k<m2;k++)
            {
                a[i][j]+=a[i-1][k]*d[k][j];
            }
        }
    }
    
    __int64 ans=0;
    for(int i=0; i<m2; i++)
    {
        ans+=a[n][i];
    }
    cout<<ans;
    
 } 

