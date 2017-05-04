#include <fstream>
using namespace std;
#define m 10010

int main()
{
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    int n,i,j,k;
    p>>n;
    int a[m],b[m],c[m];
   
    for(i=0; i<n; i++)
        p>>a[i],c[i]=1;

    for(i=n-1; i>=0; i--)
    {
        k=-1;
        for(j=n-1; j>=0; j--)
        {
            if(c[j]) k++;
            if(a[i]==k) break;
        }
        
        c[j]=0;
        b[i]=j+1;
    }
    for(i=0; i<n ;i++)
        o<<b[i]<<" ";
} 



