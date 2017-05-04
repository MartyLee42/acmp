#include <fstream>
using namespace std;


int main()
{
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    
    __int64 n,k,i,s=0,l=1;
    p>>n>>k;

    
    for(i=9; i>1; i--)
        while(k%i==0) 
        {
            if(s<n)
            s+=l*i;
            l*=10;
            k/=i;
        }

    
    if(k!=1 || s>n) o<<"NO";
    else
    o<<"YES";
        
    
}


