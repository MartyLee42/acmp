#include <fstream>

using namespace std;
#define M 1010

int main()
{
    ifstream k("INPUT.txt");
    ofstream o("OUTPUT.txt");

    int n,i,j,b=0;
    int a[M][M];
    char p[M];
    k>>n;
    for(i=1; i<=n; i++)
    {
        k>>p;
        for(j=1; j<=n; j++)
            a[i][j]=p[j-1]-'0';
    }

    for(i=n; i>0; i--)
        for(j=n; j>0; j--)
            if(a[i][j])
            {
                a[i][j]=min(a[i][j+1],min(a[i+1][j+1],a[i+1][j]))+1;
                if(a[i][j]>b) b=a[i][j];
            }

    o<<b*b;
} 

