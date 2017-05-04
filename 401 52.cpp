#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int a1[50];
int w[51];

void razl(int b,int zn)
{
    for(int j=2; j<=b; j++)
    {
        int k=j;
        for(int i=2; i<50; i++)
        {
            while(k%i==0)
            {
                k/=i;
                a1[i]+=zn;
            }
        }
    }
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n,a,b,p,size=1;
    in>>n>>a>>b;

    razl(a,-1);
    razl(b,-1);
    razl(n+a,1);
    razl(n+b,1);
    razl(n,-2);
    
    w[50]=1;
    
    for(int i=0; i<50; i++)
    {
        int ans=1;
        for(int j=0;  j<a1[i]; j++)
        {
            ans*=i;
        }
        a1[i]=ans;
    }

    int pere;
    for(int j=0; j<50; j++)
    {
        if(a1[j]!=0)
        {
            pere=0;
            for(int i=50; i>=50-size; i--)
            {
                p=(w[i]*a1[j])+pere;
                w[i]=p%10000;
                pere=p/10000;
            }  
            if (pere>0) 
            {
                size++;
                w[50-size]=pere;
            }
        }
    }

    string str;

    int l;
    
    for(l=0; l<50; l++)
    {
        if(w[l]!=0) break;
    }
    int o=1;

    out<<w[l];
    for(int q=l+1; q<=50; q++)
    {
        o=1000;
        while(w[q]/o==0)
        {
            o/=10;
            if(o==0)
            {
                break;
            }
            out<<0;
            
        }

        out<<w[q];
    }
} 

