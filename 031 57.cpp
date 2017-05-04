#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    __int64 a,b;
    in>>a>>b;

    __int64 ans=1,ans2=1;
    for(int i=0; i<a; i++)
    {
        ans*=i+1;
    }
    for(int i=0; i<b; i++)
        ans/=i+1;
    for(int i=0; i<a-b; i++)
        ans/=i+1;

    for(int i=0; i<a-b; i++)
        ans2*=i+1;
    __int64 n=(__int64)((double)(ans2+1)/2.718281828459045235360287);
    if(a==b) n=1;
    out<<n*ans;

} 

