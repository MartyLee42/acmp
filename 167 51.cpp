#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    __int64 n;
    in>>n;

    if(n%2==0)
    {
        n/=2;
        out<<n*(n+1)*(4*n+1)/2;
    }
    else
    {
        n/=2;
        out<<(n+1)*(4*n*n+7*n+2)/2;
    }
} 


