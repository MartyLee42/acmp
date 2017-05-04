#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    __int64 l;
    in>>l;
    __int64 k=1,n=2,s=0;

    
    while(true)
    {

        s=(k+n-2)*(n-1-k)+2*n-2;

        if(l<s)
        {
            
            s-=n;
            if(l==s)out<<"LOSE";
            if(l>s) out<<"WIN";
            
            if(l<s)
            {
                int a=(int)((-2*k-3+sqrt(double((2*k+3)*(2*k+3)-4*(2*k-l))))/2);
                l-=(2*k+a+1)*(a);
                k+=a;
                if(l==0 || l==k+1|| l==2*k+2|| l==3*k+4 || l==4*k+6) out<<"LOSE";
                else 
                {
                    l-=k+1;
                    k++;
                    if(l==0 || l==k) out<<"LOSE";
                    else out<<"WIN";
                }


            }
            break;
        }
        if(l==s)
        {   
            out<<"LOSE";
            break;
        }
        l-=s;
        k=n;
        n*=2;
        
    
    }
    
    
}

