#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 1000
int a[Max];

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n,b=1,size=1,p;
    in>>n;
    
    a[Max-1]=1;
    
    int pere;
    for(int j=0; j<n; j++)
    {
        pere=0;
        for(int i=Max-1; i>=Max-size; i--)
        {
            p=(a[i]*b)+pere;
            a[i]=p%10000;
            pere=p/10000;
        }  
        if (pere>0) 
        {
            size++;
            a[Max-size]=pere;
        }
        b++;
    }

    string str;

    int l;
    
    for(l=0; l<Max; l++)
    {
        if(a[l]!=0) break;
    }
    int o=1;

    out<<a[l];
    for(int q=l+1; q<Max; q++)
    {
        o=1000;
        while(a[q]/o==0)
        {
            o/=10;
            if(o==0)
            {
                break;
            }
            out<<0;
            
        }

        out<<a[q];
    }
} 

