#include <fstream>
using namespace std;
int cc[40][40];

__int64 C(__int64 k,__int64 n)
{
    __int64 l=1;
    if(k==0 && n==0) return 1;
    if(k<0 || n<=0) return 0;
    l=cc[n][k];
    return l;
}

int main()
{
    int g[100];
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    __int64 n,k,p=0;
    in>>n>>k;
    
    for(int i=0; i<40; i++)
    {
        cc[i][0]=1;
    }
    for(int i=1; i<35; i++)
    {
        for(int j=1; j<35; j++)
        {
            
            cc[i][j]=cc[i-1][j-1]+cc[i-1][j];
        }
    }

    while(n)
    {
        (n%2==1 ? g[p]=1 : g[p]=0);
        p++;
        n/=2;
    }

    int ans=0,zer=1;

    for(int i=p-2; i>=0; i--)
    {
        if(g[i]==1)ans+=C(k-zer,i);
        if(g[i]==0) zer++;
    }
    for(int i=p-2; i>0; i--)
    {
        ans+=C(k,i);
    }
    for(int i=p-1; i>=0; i--)
    {
        if(g[i]==0)k--;
    }

    if(k==0) ans++;
    if (k>p) 
    {
        out<<0;
        return 0;
    }
    out<<ans;
    
} 

