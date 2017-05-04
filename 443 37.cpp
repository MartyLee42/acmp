#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

int hash(int x,int m, char *s)
{
    int i=0,ans=0,x1=1;
    while(s[i]>0) i++;
    for(int j=0; j<i; j++)
    {
        ans+=(s[j]-'0')*x1;
        ans%=m;
        x1*=x;
        x1%=m;
    }
    return ans;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n,m,x,k[4000];
    memset(k,0,16000);
    in>>n>>m>>x;
    char a[200];
    for(int i=0; i<n; i++)
    {
        in>>a;
        k[hash(x,m,a)]++;
    }
    int ans=0;
    for(int i=0; i<m; i++)
    {
        if(k[i]>1) ans+=(k[i]-1)*(k[i])/2;
    }
    out<<ans;
}



