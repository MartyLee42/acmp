#include <fstream>

int A(int n, int k)
{
    int a=1;
    for(int i=n; i>n-k; i--)

        a*=i;
    return a;
}


int main()
{
    std::ifstream c("INPUT.txt");
    std::ofstream o("OUTPUT.txt");
    int n, k,a,b[20],r=0;
    c>>n>>k;

    
    memset(b,0,80);
    for(int i=0; i<k; i++)
    {
        int l=0;
        c>>a;
        for(int j=1; j<a; j++)
            if(b[j]==0) l++;    
        r+=l*A(n-i-1,k-i-1);
        b[a]=1;
    }

    o<<r+1;
 } 





