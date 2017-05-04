#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int k,n;
    int a1[100];
    int a2[100];
    in>>n;
    in>>k;
    a1[0]=k-1;
    a2[0]=0;
    for(int i=1; i<n; i++)
    {
        a1[i]=(a1[i-1]+a2[i-1])*(k-1);
        a2[i]=a1[i-1];
    }
    out<<a1[n-1]+a2[n-1];
} 

