#include <fstream>
using namespace std;

int main()
{
    int n,x,y,a;
    ifstream i("INPUT.txt");
    ofstream o("OUTPUT.txt");
    i>>n>>x>>y;
    n--;
    if (x>y) swap(x,y);
    a=(y*(n+1))/(x+y);
    a*x>(n-a)*y? a*=x:a=(n-a)*y;
    a+=x;
    o<<a;
} 


