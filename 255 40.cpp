#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool b[35000];

int lPrime(int a)
{
    for(int i=2; i<35000; i++)
    {
        if(b[i])
        {
            if(a%i==0) return i;
        }
    }
    return a;
}

    
int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    memset(b,true,35000);

    for(int i=2; i<200;i++)
    {
        if(b[i])
        {
            for(int j=2*i; j<35000; j=j+i)
            {
                b[j]=false;
            }
        }
    }

    int a;
    
    in>>a;
    int c=lPrime(a);
    if(c==a)
    {
        out<<1<<" "<<a-1;
        return 0;
    }
    
    out<<a/c<<" "<<a-(a/c);
} 

