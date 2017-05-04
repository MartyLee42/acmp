#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

__int64 a,b,c,d;
__int64 rr[10],n=0;

bool root(__int64 x)
{
    double xx=double(x);
    if(xx*xx*xx*a+xx*xx*b+c*xx+d>1000000) return false;
    if((c+x*(a*x+b))+d/x==0) return true;
    
    if(abs(xx*xx*xx*a+xx*xx*b+c*xx+d)<0.5) return true;
    return false;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    memset(rr,0,10*4);

    in>>a>>b>>c>>d;
    __int64 dd=d;
    if(d==0)
    {
        rr[n]=0;
        n++;
        if(c==0)
        {
            if(b==0)
            {
                if(a==0)
                {
                    out<<-1;
                    return 0;
                }
                dd=a;
            }
            else
                dd=b;
        }
        else
            dd=c;
    }
    if(dd<0) dd=-dd;

    int deliteli[100000],nn=1;
    memset(deliteli,0,100000*4);
    deliteli[0]=1;
    __int64 ddd=sqrt(double(dd))+10;
    for(int i=2; i<ddd; i++)
    {
        int ii=i;
        int nnn=0;
        while(dd%i==0)
        {
            for(int j=0; j<nn; j++)
                deliteli[j+nnn+nn]=ii*deliteli[j];

            ii*=i;
            dd/=i;
            nnn+=nn;
        }
        nn+=nnn;
        if(dd==1) break;
    }
    if(dd!=1)
    {
        for(int j=0; j<nn; j++)
                deliteli[j+nn]=dd*deliteli[j];
        nn*=2;
    }

    for(int i=0; i<nn; i++)
    {
        if(root(deliteli[i]))
        {
            rr[n]=deliteli[i];
            n++;
        }
        if(root(-deliteli[i]))
        {
            rr[n]=-deliteli[i];
            n++;
        }
    }

    sort(rr,rr+n);

    out<<n;
    for(int i=0; i<n;i++)
    {
        out<<" "<<rr[i];
    }
}

 




