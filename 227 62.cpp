#include <fstream>
#include <math.h>
using namespace std;


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    __int64 a,b;
    in>>a>>b;

    if(a*b>0)
    {
        if(a<0)
        {
            a=-a;
            b=-b;
        }

        if(a>b || b % a !=0) 
        {
            out<<-1;
            return 0;
        }

        b/=a;
        int s=0;

        for(int i=2; i<int(sqrt(double(b))+1); i++)
        {
            while(b%i==0)
            {
                b/=i;
                s+=i;
            }
        }
        if(b!=1) s+=b;
        out<<s;

    }
    else 
    {
        if(a==b && a==0) out<<0;
        else out<<-1;
    }

} 


