#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool prime(int a)
{
    if(a==1) return false;
    for(int i=2; i<47000; i++)
    {
        if(a%i==0)
        {
            if(a==i) return true;
            return false;
        }
    }
    return true;
}

int s(int a)
{
    int ans=0;
    while(a>0)
    {
        ans+=a%10;
        a/=10;
    }
    return ans;
}

int PCK(int a)
{
    if(prime(a))return a;
    if(a<10) return 0;
    return PCK(s(a));
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int a;
    in>>a;
    out<<PCK(a);
} 

