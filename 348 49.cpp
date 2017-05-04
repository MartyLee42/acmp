#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int sov=0;
    double x1,x2,y1,y2,a1,a2,b1,b2,x,y;
    double c1,c2,d1,d2;
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    in>>x1;
    in>>y1;
    in>>x2;
    in>>y2;

    in>>a1;
    in>>b1;
    in>>a2;
    in>>b2;
    
    

    if (x1==x2)
    {
        d1=10000000000000000001;
        c1=x1;
    }
    else
    {
        d1=(y1-y2)/(x1-x2);
        c1=y1-x1*d1;
    }

    if (a1==a2)
    {
        d2=10000000000000000001;
        c2=a1;
    }
    else
    {
        d2=(b1-b2)/(a1-a2);
        c2=b1-a1*d2;
    }

    if ((d1<100000000000000)&(d2<10000000000000))
    {
        if ((d1-d2)!=0)
        {
            x=(c2-c1)/(d1-d2);
            y=d1*x+c1;
        }
        else
        {
            if(c1==c2)
            {
                sov=1;
            }
            else
            {
                sov=-1;
            }

        }
    }
    else
    {
        if(d1>100000000000000)
        {
            y=d2*c1+c2;
            x=c1;
        }
        if(d2>100000000000000)
        {
            y=d1*c2+c1;
            x=c2;
        }
        if(d1==d2)
        {
            if(c1==c2)
            {
                sov=1;
            }
            else
            {
                sov=-1;
            }
        }
    }

    if (x1>x2) swap(x1,x2);
    if (y1>y2) swap(y1,y2);
    if (a1>a2) swap(a1,a2);
    if (b1>b2) swap(b1,b2);


    if (sov==0)
    {

        if ((x<=x2)&(x>=x1)&(y<=y2)&(y>=y1)&(x<=a2)&(x>=a1)&(y<=b2)&(y>=b1))
        {
            out<<"Yes";
        }
        else
        {
            out<<"No";
        }
        
    }
    if (sov==1)
    {
        if ((a2<x1)||(a1>x2))
        {
            out<<"No";
        }
        else
        {
            if ((b2<y1)||(b1>y2))
            {
                out<<"No";
            }
            else
            {
                out<<"Yes";
            }
        }
    }
    if (sov==-1)
    {
        out<<"No";
    }
    
    
} 


