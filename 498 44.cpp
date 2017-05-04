#include <fstream>
using namespace std;


int n,ans=0;
  int p;
ofstream out("OUTPUT.txt");

int a[9];
char c=10,c1=13;

void reverse(int m)
{
    int j=0;
    while(j<m-1)
    {
        swap(a[j],a[m-1]);
        j++;
        m--;
    }
}

void lex(int m)
{
    if(m==1) 
    {
        bool tr=true;
        for(int i=0; i<n-1; i++)
        {
            if(abs(a[i]-a[i+1])>p) 
            {
                tr=false;
                break;
            }
        }
        if(tr) ans++;
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            lex(m-1);
            if(i<m-1)
            {
                swap(a[i],a[m-1]);
                reverse(m-1);
            }
        }
    }
}



int main()
{
    ifstream in("INPUT.txt");
    
  
    in>>n>>p;
    for(int i=0; i<n; i++)
    a[i]=i+1;

    lex(n);
    
    
    out<<ans;

} 



