#include <fstream>
using namespace std;
int m[200],i,n,j;

int main()
{
    
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    p>>n;
    m[0]=1;
    for(i=1;i<=n; i++)
        for(j=99; j>=0; j--)
            m[j+i]+=m[j];
    o<<m[n];
} 

