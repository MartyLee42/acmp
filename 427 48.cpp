#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream p("INPUT.txt");
    std::ofstream o("OUTPUT.txt");

    __int64 a[10000],n,i,j,k=1;
    p>>n;
    for(i=0; i<n; i++)
        p>>a[i];
    
    std::sort(a,a+n);

    for(i=0; i<n; i++)
        a[i]>k ? k=k: k+=a[i];
    o<<k;
} 

