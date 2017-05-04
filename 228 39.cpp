#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    ifstream in("INPUT.txt");
    FILE *out=fopen("OUTPUT.txt","w");

    int n;
    double a,b;
    in>>n;
    
    double r=100,d=0,e=0;
    
    for(int i=0; i<n; i++)
    {
        in>>a>>b;
        if(r<d*a) r=d*a;
        if(r<e*b) r=e*b;
        if(d<r/a) d=r/a;
        if(e<r/b) e=r/b;
        
    }
    
    fprintf(out,"%.2f",r);
} 


 