#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    __int64 n,max1=-30000,max2=-30000,max3=-30000,min1=30000,min2=30000;
    in>>n;

    int h;
    for(int i=0; i<n ;i++)
    {
        in>>h;
        if(h>max1)
        {
            max3=max2;
            max2=max1;
            max1=h;
        }
        else
        {
            if(h>max2)
            {
                max3=max2;max2=h;
            }
            else
            {
                if(max3<h)
                    max3=h;
            }
            
        }
        if(h<min1)
        {
            min2=min1;
            min1=h;
        }
        else
        {
            if(h<min2)
                min2=h;
        }
    }
    if(max1>0 && min1*min2>max2*max3)
    {
        out<<max1*min1*min2;
    }
    else
    {
        out<<max1*max2*max3;
    }
} 

