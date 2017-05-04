#include <iostream>
#include <fstream>
using namespace std;    

int w[20];

int mm(int n)
{
    int ans=0,i=0;
    while(n>0)
    {
        if(n%2==1) ans+=w[i];
        n>>=1;
        i++;
    }
    return ans;
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    
    int n,s=0,l=1;
    in>>n;
    for(int i=0;i<n; i++)
    {
        in>>w[i];
        s+=w[i];
        l*=2;
    }
    l/=2;
    int min=10000000;
        for(int i=1; i<=l; i++)
        {
            int y=mm(i);
            if(abs(s-2*y)<min)min=abs(s-2*y);
        }

    out<<min;

}
    

