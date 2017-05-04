#include <iostream>
#include <fstream>
using namespace std;

int b[50];

ofstream out("OUTPUT.txt");

void print()
{
    out<<b[1];
    int i=2;
    while(b[i]>0)
    {
        out<<"+"<<b[i];
        i++;
    }
    out<<"\n";

}

void pere(int n, int i, int k)
{
    for(int j=1; j<=k && j<=n; j++)
    {
        b[i]=j;
        pere(n-j,i+1,j);
    }
    if(n==0)
    {
        print();
        b[i-1]=0;
    }
}



int main()
{
    ifstream in("INPUT.txt");
    int n;
    in>>n;
    memset(b,0,200);
    for(int j=1; j<n; j++)
    {
        b[1]=j;
        pere(n-j,2,j);
    }
    
}
