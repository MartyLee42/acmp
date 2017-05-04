#include <fstream>

using namespace std;

__int64 f(int n)
{
    if(n==0) return 1;
    return f(n-1)*n;
}

int main()
{
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    int n,m,a=0;
    p>>n>>m;
    
    for(int i=0; i<=n-m; i++)
        a+=f(n)/f(n-i)/f(i);
    o<<a;
    
}


