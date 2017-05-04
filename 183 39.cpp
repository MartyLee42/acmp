#include <fstream>
using namespace std;

int main()
{
    ifstream y("INPUT.txt");
    ofstream o("OUTPUT.txt");
    
    int n,p,i,x[1000010];
    y>>n>>p;
    x[2]=1;
    x[1]=0;
    for(i=3; i<=n; i++)
        x[i]=i%2==1?x[i-1]:(x[i-1]+x[i/2])%p;
    p==1?o<<0:o<<x[n];

}


