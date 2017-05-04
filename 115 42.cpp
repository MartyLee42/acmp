#include <fstream>
#include <math.h>

using namespace std;


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    int n,k;
    in>>n>>k;
    int a[101][101];
    int c[101][101];
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            in>>a[i][j];
            if(i>0)
                c[i][j]=c[i-1][j]+a[i][j];
            else
                c[i][j]=a[i][j];
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int l=1; l<=i; l++)
        {
            int a=0;
            for(int j=1; j<=k; j++)
            {
                a=max(a+c[i][j]-c[i-l][j],c[i][j]-c[i-l][j]);
                ans=max(a,ans);
            }
        }
    }

    
    out<<ans;
} 

