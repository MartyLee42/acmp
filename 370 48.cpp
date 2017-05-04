#include <iostream>
#include <fstream>
using namespace std;
int p[60000][2];
int c;

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
    out<<S/2;
    out<<'.';
    if(S%2==0)
        out<<'0';
    else
        out<<'5';
} 



