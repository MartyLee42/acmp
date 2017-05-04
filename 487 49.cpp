#include <fstream>
using namespace std;


int main()
{
    ifstream y("INPUT.txt");
    ofstream o("OUTPUT.txt");
    
    int n,k,p,a,i;
    y>>n>>k>>p;
    for( i=0; i<p; i++)
    {
        y>>a;
        n-=a;
        n%(k+1)==0||(n+a)%(k+1)==0?o<<"T":o<<"F";
        o<<"\n";
    }
}


