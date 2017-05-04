#include <fstream>
using namespace std;

int main()
{
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    char a[10000];
    int k,m,n,l=0,b=1,c=0;
    p>>k>>m>>a;

    while(a[l]>0) l++;

    while(l>0)
    {
        l--;
        if(a[l]<='9')
            c+=b*(a[l]-'0');
        else c+=b*(a[l]-'A'+10);
        c%=m;
        b=b*k%m;
    }
    o<<c;
} 

