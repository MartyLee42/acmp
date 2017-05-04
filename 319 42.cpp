#include <fstream>
#include <iostream> 
using namespace std;

int GCD(int a, int b)
{
    int c;
    while ( b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int ab(int x)
{
    if(x<0) return -x;
    return x;
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    __int64 a,b,x,y;
    in>>a>>b>>x>>y;

    out<<(GCD(ab(a-x),ab(b-y))+1);
}
 


