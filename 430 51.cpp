#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    long double R,f1,f2,l1,l2;
    in>>R;
    in>>f1;
    in>>l1;
    in>>f2;
    in>>l2;
    long double p=3.14159265358979323846264338327950288419716939937510/180;
    long double d=((sin(f1*p)*sin(f2*p)+cos(f1*p)*cos(f2*p)*cos((l1-l2)*p)));
    
    d=R*acos(d);
    if (d<0) d=-d;
    int m=(int)d;
    int h=(int)((100*d));
    h=h-100*m;
if((f1==f2)&&(l1==l2))
out<<"0.00";
else
{
    out<<m;
    out<<'.';
    if(h<10) out<<'0';
    out<<h;
}
}



