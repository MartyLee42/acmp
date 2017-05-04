#include <fstream>
#include <math.h>
using namespace std;


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    double x1,x2,y1,y2;
    double count=0;
    in>>x1>>y1>>x2>>y2;

    double x,y,z,h,p;

    x=sqrt(x1*x1+y1*y1);
    y=sqrt(x2*x2+y2*y2);
    z=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    p=(x+y+z)/2;
    
    h=2*sqrt(p*(p-z)*(p-y)*(p-x))/z;
    if(z*z+h*h>=y*y)
    {
        count=int(x)-int(h)+int(y)-int(h);
        if(abs(h-int(h))<0.001 && h>0.001) count++;
    }
    else
    {
        if(x>y) swap(x,y);
        count=int(y)-int(x);
    
        if(x==int(x) && (x>0.001 || y>0.001)) count++;
    }
    if(count<0) count=0;
    out<<count;
} 


 





