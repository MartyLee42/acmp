#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 1010

class bigint
{
public:
    bigint()
    {
        memset(a,0,2*Max);
        sign=0;
        size=0;
    };
    operator string();
    bigint operator+( bigint &b );
    bigint operator=( bigint &b);
    bigint operator=( string &str);
    bigint operator=(char str[Max]);
    
    private:
        short a[Max];
        short sign;
        int size;
};

 bigint::operator string()
{
    int k=0,j=0;
    string str;
    if(sign!=0) str="-";
    for(j=0; j<Max; j++)
    {
        if(a[j]!=0) break;
    }
    k=0;
    for(j=j;j<Max; j++)
    {
        str+=(char)(a[j]+'0');
    }
    if(str[0]==0) str="0";
    return(str);
}

bigint bigint::operator+( bigint &b ) 
{    
    bigint h;
    int perenos=0;
    int s=0;
    if (size < b.size) s=b.size;
    else
        s=size;
    for(int i=Max-1;i>=Max-s;i--)
    {
        h.a[i]=(a[i]+b.a[i]+perenos)%10;
        perenos=(a[i]+b.a[i]+perenos)/10;
    }
    h.size=s;
    if(perenos>0)
    {
        h.a[Max-s-1]=perenos;
        h.size++;
    }
    return(h);
}
bigint bigint::operator =(bigint &b)
{
    memcpy(&a,&b.a,2*Max);
    sign=b.sign;
    size=b.size;
    return(bigint());
}

bigint bigint::operator =(string &str)
{
    int len=str.length();
    if(str[0]=='-') sign=1;
    size=len;
    for(int i=len-1;i>=0; i--)
    {
        a[Max-len+i]=(int)(str[i]-'0');
    }
    return(bigint());
}

bigint bigint::operator =(char str[Max])
{
    int len=0;
    for(int i=0; i<Max; i++)
    {
        if (str[i]==0) 
        {
            len=i;
            break;
        }
    }
    for(int i=len-1;i>=0; i--)
    {
        a[Max-len+i]=(int)(str[i]-'0');
    }
    size=len;
    return(bigint());
}

bigint m[310];
int main()
{
   
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
   
    int k,n;

    in>>k>>n;

    m[1]="1";
    for(int i=1; i<=301; i++)
    {
        for(int j=i-1; (j>=i-k && j>=0); j--)
        {
            m[i]=m[i]+m[j];
        }
    }
  
    string str;
    str=string(m[n+1]);
    out<<str;
} 


