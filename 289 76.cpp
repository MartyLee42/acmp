#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

double Div[129];

double primes[]={0,2,3,5,7,11,13,17,19,23,29,31,37};

__int64 Max=1,Min;

void test(int num)
{
    double ans,z;
    ans=1;
    for(int k=1; k<=num; k++)
    {
        z=pow(primes[k],Div[k]-1);
        if(z > Max)  
            return;
        ans*=z;
        if(ans > Min) 
            return;
    }
    Min=ans;
}



void build(int ind ,int nn)
{
    int d;
     if (nn==1)
      {
          test(ind-1);
          return;
      }
     for (d=2; d<=nn; d++) 
    {
          if (ind>1 && Div[ind-1]<d) break;
          if (nn % d==0)
           {
               Div[ind]=d;
               build(ind+1,nn/d);
           }
      }
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    __int64 n;
    in>>n;

    for(int l=1;l<=15; l++) Max=Max*10;
    Max++;
    Min=Max;
    build(1,n);
    if(Min>=Max) Min=0;
    out<<Min;

} 

