#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    __int64 n;
    in>>n;
    if(n%4==0) 
    {
    out<<3;
    return 0;
    }
    while(n%2==0) n/=2;
    for(__int64 i=3; i<=20000; i++)
        if(n%i==0) 
        {
            out<<i-1;return 0;
        }
    if(n<3) out<<0;
    else
    out<<(n-1);
}

