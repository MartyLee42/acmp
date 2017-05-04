#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 10000
typedef char ch[Max];

class bigint
{
public:
    bigint(){
        for(int i=0; i<Max; i++)
            a[i]=0;
    };
    operator string();
    bigint operator+( bigint b );
    bigint operator=( bigint &b);
    bigint operator=( string &str);
    bigint operator=(char str[Max]);
    bigint operator*( bigint b);
    bigint operator*(const int b);
    
    
private:
    int a[Max];
};
 bigint::operator string()
{
    int k,j;
    string str;
    for(j=0; j<Max; j++)
    {
        if(a[j]!=0) break;
    }
    k=0;
    for(j=j;j<Max; j++)
    {
        str+=(char)(a[j]+'0');
    }
    return(str);
}

bigint bigint::operator+( bigint b ) 
{    
    int perenos=0;
    bigint h;
    for(int i=Max-1;i>=0;i--)
    {
        h.a[i]=(a[i]+b.a[i]+perenos)%10;
        perenos=(a[i]+b.a[i]+perenos)/10;
    }
    return(h);
}
bigint bigint::operator =(bigint &b)
{
    memcpy(&a,&b,4*Max);
    return(bigint());
}

bigint bigint::operator =(string &str)
{
    int len=str.length();
    for(int i=len-1;i>=0; i--)
    {
        a[Max-len+i]=(int)(str[i]-'0');
    }
    return(bigint());
}

bigint bigint::operator =(char str[Max])
{
    int len;
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
    return(bigint());
}


bigint bigint::operator*(bigint b)
{
    bigint C;
    bigint B;
    int i,j;
    int res,k;
    for (i = Max-1; i > 0; i--)
    {
        B=(b*a[i]);
        for(int l=Max-1; l>i; l--)
        {
            j=l-Max+i+1; k=B.a[l]; B.a[l]=0;
            while(j>=0)
            {
                res=B.a[j];
                B.a[j]=k;
                k=res;
                j-=Max-i-1;
            }
        }
        C=C+B;
    }
    return C;
}

bigint bigint::operator *(const int b) 
{
    bigint C;
    int pere=0;
    for(int i=Max-1; i>=0; i--)
    {
        C.a[i]=(a[i]*b)%10+pere;
        pere=(a[i]*b/10);
    }    
    return C;
}

int main()
{
    FILE *in;
    char a[200];
    int b=0;
    
    in=fopen("INPUT.txt","r");
    ofstream out("OUTPUT.txt");

    fscanf(in,"%d",&b);
    
    bigint c;
    c="2";
    for(int i=1; i<b; i++)
    {
        c=c*2;
    }
    string c1;
    char h;
    c1=string(c);
    out<<c1;
    
} 

