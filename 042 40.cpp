#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;
    in>>n;
    __int64 a;
    if(n%3==1)
        a=pow(3.0,(n/3-1))*4;
    if(n%3==0)
        a=pow(3.0,(n/3));
    if(n%3==2)
        a=pow(3.0,(n/3))*2;
    out<<a;
} 

