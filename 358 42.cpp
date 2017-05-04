#include <iostream>
#include <fstream>
using namespace std;
__int64 p[3][2];
__int64 c;

__int64 GCD(__int64 a, __int64 b)
{
    while ( b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

__int64 A(__int64 a)
{
    if (a<0) return(-a);
    return(a);
}

__int64 intPoints()
{
    __int64 ans=0;
    for(int i=0; i<3; i++)
    {
        ans+=GCD(A(p[(i+1)%3][0]-p[i][0]),A(p[(i+1)%3][1]-p[i][1]));
    }
    return(ans);
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
        
    for(int i=0; i<3;i++)
    {
        in>>p[i][0];
        in>>p[i][1];
    }
    __int64 M=intPoints();
    if(M==0) M=1;
    
    out<<M;
} 


