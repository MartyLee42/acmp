#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;

    in>>n;

    int i=5;
    int k=0;

    while(i<=n)
    {
        k+=n/i;
        i*=5;
    }
    
    i=1;
    int ans=1;
    while(i<=n)
    {
        int l=i;
        while((l%2==0)&(k>0))
        {
            l/=2;
            k--;
        }
        while(l%5==0)
        {
            l/=5;
        }
        ans*=l;
        ans=ans%10;
        i++;
    }

    out<<ans;
} 

