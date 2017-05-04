#include <iostream>
#include <fstream>
using namespace std;
int p[1000][2];
int c;

int GCD(int a, int b)
{
    while ( b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int A(int a)
{
    if (a<0) return(-a);
    return(a);
}
__int64 A(__int64 a)
{
    if (a<0) return(-a);
    return(a);
}

int intPoints(__int64 n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=GCD(A(p[(i+1)%n][0]-p[i][0]),A(p[(i+1)%n][1]-p[i][1]));
    }
    return(ans);
}

__int64 area(int n)
{
    __int64 a=0;
    for(int i=0; i<n; i++)
    {
        a+=(__int64)(p[i][0]+p[(i+1)%n][0])*(__int64)(p[i][1]- p[(i+1)%n][1]);    
    }
    return(a);
}
int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
        
    int n;
    in>>n;
    for(int i=0; i<n;i++)
    {
        in>>p[i][0];
        in>>p[i][1];
    }
    __int64 S=A(area(n));
    __int64 M=intPoints(n);
    __int64 k=(S-M+2)/2;
    
    out<<k;
} 

