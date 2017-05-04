#include <fstream>
using namespace std;

__int64 q[50][50],n,l;
__int64 v(int a, int b)
{
    if(a<b) return v(b,a);
    if(q[a][b]!=0) return q[a][b];
    if(a>b & a>24) return v(a-1,b);
    if(a==1 & b==1) return 2;
    if(a==0 || b==0) return 1;
    __int64 k;
    k=(v(a-1,b)+v(a,b-1));
    q[a][b]=k;
    return k;
}

    
int main()
{
    ifstream p("INPUT.txt");
    ofstream o("OUTPUT.txt");
    char h;
    p>>n>>h>>l;

    (n<25 & l<25||n>l & n>25 & n-l>2||l>25 & l-n>2)?o<<0:o<<v(n,l);
} 

