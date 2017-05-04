#include <fstream>
using namespace std;

int GCD(int a, int b)
{
    int c;
    while ( b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCF(int a, int b) 
{
    return (a / GCD(a, b) ) * b;
}



int main()
{
    int g[101];
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;
    in>>n;

    for(int i=1; i<=n; i++)
        in>>g[i];
    
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        int k=1;
        int j=i;
        while(g[j]!=i)
        {
            k++;
            j=g[j];
        }
        ans=LCF(ans,k);
    }
   
    out<<ans;
} 


