#include <fstream>
#include <algorithm>


int main()
{
    std::ifstream q("INPUT.txt");
    std::ofstream o("OUTPUT.txt");
    int n, a[110],l,i,b;

    q>>l>>n;

    for(i=0; i<n; i++)
        q>>a[i];

    std::sort(a,a+n);
    i=n-2;
    b=a[i];

    for(i; i>=0; i--)
        b-a[i]>2*l?b=a[i]:n--;

    o<<n;
}

