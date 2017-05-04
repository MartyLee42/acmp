#include <fstream>
#include <iostream> 
using namespace std;

__int64 odin(char a[100],__int64 b, __int64 x)
{
    __int64 ans=0,m=1;
    
    if(a[b]=='-') m=-1;
    b++;
    if(a[b]!='x')
    {
        while(a[b]!='-' && a[b]!='+' && a[b]!='*' && a[b]!=0)
        {
            ans=ans*10+a[b]-'0';
            b++;
        }
    }
    else
    {
        ans=1;
        b--;
        a[b]='*';
    }
    if(a[b]=='*')
    {
        b++;
        b++;
        if(a[b]=='+' || a[b]=='-' || a[b]==0)
        {
            ans*=x;
        }
        else
        {
            b++;
            for(int i=0; i<a[b]-'0'; i++)
            {    
                ans*=x;
            }
        }
    }
    return(ans*m);
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    char a[100];__int64 x,ans=0,len=0;
    in>>a;
    in>>x;

    if(a[0]!='-')
    {
        char t=0;
        for(int y=98; y>=0; y--)
        {
            a[y+1]=a[y];        
        }
        a[0]='+';
    }

    while(a[len]!=0) len++;
    
    for(int i=1; i<len; i++)
    {
        int b=i-1;
        while(a[i]!='-'&& a[i]!='+' && a[i]!=0) i++;
        ans+=odin(a,b,x);
    }
    out<<ans;
}
 




