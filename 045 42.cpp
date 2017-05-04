#include <iostream>
#include <fstream>
#include <string>
using namespace std;    

int main()
{
    int a[9];
    memset(&a,0,36);
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n;
    in>>n;

    if(n==0) 
    {out<<10;
    return 0;
    }
if(n==1)
{
    out<<1;
return 0;
}
    for(int i=9; i>=2; i--)
    {
        while(n%i==0)
        {
            a[i-1]++;
            n/=i;
        }
    }
    if(n!=1) 
    {
        out<<-1;
        return 0;
    }
    for(int i=0; i<9; i++)
    {
        while(a[i]>0) 
        {
            out<<i+1;
            a[i]--;
        }
    }
} 

