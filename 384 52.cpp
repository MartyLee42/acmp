#include <iostream>
#include <fstream>
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

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    __int64 n,k;
    in>>n;
    in>>k;
    int g=GCD(n,k);
    int a=1,b=0,t;
    for(int j=1; j<g; j++)
    {
        t=a;
        a=(a+b)%1000000000;
        b=t;
    }

    out<<a;
}


