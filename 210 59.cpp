#include <iostream>
#include <fstream>
using namespace std;
bool primes[45000];
int p[35][2];

__int64 po(__int64 a)
{
    __int64 ans=1;
    for(int i=0; i<a; i++) 
        ans*=a;
    return ans;
}

void pr(int a)
{
    int j=0;
    for(int i=2; i<45000; i++)
    {
        if(primes[i])
        {
            if(a%i==0)
            {
                p[j][0]=i;
                j++;
            }

            while(a%i==0) 
            {
                a/=i;
                p[j-1][1]++;
            }
        }
    }
    if(a!=1) p[j][0]=a;
        
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    memset(primes,true,45000);
    memset(p,0,140);

    for(int i=2; i<300; i++)
    {
        if(primes[i])
        {
            for(int j=i*2; j<45000; j=j+i)
                primes[j]=false;
        }
    }

    int a;
    in>>a;

    pr(a);

    int k=0;
    int ans=1;
    while(p[k][0]!=0)
    {
        ans*=p[k][0];
        k++;
    }
    for(int i=1; i<15; i++)
    {
        if(po(i)%a==0) 
        {
            out<<i;
            return 0;
        }
    }


    
    int j=1;
    for( j=1; j<40; j++)
    {
        bool tr=true;
        for(int i=0; i<k; i++)
        {
            int y=0,x=j;
            while(x%p[i][0]==0)
            {
                y++;
                x/=p[i][0];
            }
            if(p[i][1]>(ans+y)*j)tr=false;
        }
        if(tr) break;
    }
    ans*=j;

    out<<ans;
} 


