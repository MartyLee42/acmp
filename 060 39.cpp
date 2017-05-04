#include <iostream>
#include <fstream>
using namespace std;
bool primes[40000];

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;
    
    
    for (int i=0; i<=40000; i++)primes[i]=true;
    in>>n;
    
    for(int i=2; i<40000;i++)
    {
        for(int j=2*i;j<40000;j+=i)
        {
            primes[j]=false;
        }
    }
    primes[0]=false;
    primes[1]=false;
    bool t=true;
    
    int pn=0;
    int sp=0;
    int i;
    for(i=2; i<40000; i++)
    {
        if(primes[i])
        {
            pn++;
            if(primes[pn])
            {
                sp++;
                if (sp==n)
                {
                    break;
                }
            }
        }
    }
    
    out<<i;
} 

