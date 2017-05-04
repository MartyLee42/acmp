#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 2500
int a[Max];

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int y,b,p,size=1;
    in>>y>>b;
    
    a[Max-1]=y;
    
    int pere;
    for(int j=0; j<b-1; j++)
    {
        pere=0;
        for(int i=Max-1; i>=Max-size; i--)
        {
            p=(a[i]*y)+pere;
            a[i]=p%10000;
            pere=p/10000;
        }  
        if (pere>0) 
        {
            size++;
            a[Max-size]=pere;
        }
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
            out<<0;
        }

        out<<a[q];
    }
} 



