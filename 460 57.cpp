#include <fstream>
#include <iostream> 
using namespace std;

__int64 digit(__int64 x,__int64 n)
{
    for(int i=1; i<x; i++) n/=10;
    return n-(n/10)*10;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    unsigned __int64 n,ans=0;
    in>>n;

    unsigned __int64 ten=1;

    for(int i=0; i<19; i++)
    {
        ans+=((n+5*ten)/ten/10)*ten;
        
        if(digit(i+1,n)==5) ans-=(6*ten-n%(ten*10)-1);
        ten*=10;
    }
    out<<ans;
} 


