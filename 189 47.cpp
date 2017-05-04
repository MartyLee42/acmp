#include <fstream>
using namespace std;

int main()
{
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    __int64 l,n,f[13],i,k,j,c[13];
    p>>n>>l;
    f[0]=1;

    for(i=1; i<13; i++)
        f[i]=f[i-1]*i, c[i]=1;

    for(i=0; i<n; i++)
    {
        k=1;
        while(l-k*f[n-i-1]>0) k++;

        l-=(k-1)*f[n-i-1];
        for(j=0; j<n; j++)
        {
            if(c[j]) k--;
            if(k==0) break;
        }
        c[j]=0;
        o<<j+1<<" ";
    }
} 




