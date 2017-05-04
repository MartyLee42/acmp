#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 1000

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
    bigint operator-( bigint &b );
    bigint operator+( bigint &b );
    bigint operator=( bigint &b);
    bigint operator=( string &str);
    bigint operator=(char str[Max]);
    bigint operator*( bigint &b);
    bigint operator*(const int &b);
    
    private:
        short a[Max];
        short sign;
        int size;
};

 bigint::operator string()
{
    int k=0,j=0;
    string str="";
    for(j=0; j<Max; j++)
    {
        if(a[j]!=0) break;
    }
    k=0;
    for(j=j;j<Max; j++)
    {
        str+=(char)(a[j]+'0');
    }
    if (str.length()==0)
        str="0";
    return(str);
}

bigint bigint::operator+( bigint &b ) 
{    
    int perenos=0;
    bigint h;
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
    memcpy(&a,&b,2*Max);
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


bigint bigint::operator*(bigint &b)
{
    bigint C;
    bigint B;
    int i=0,j=0;
    int res,k;
    for (i = Max-1; i >= Max-size; i--)
    {
        B=(b*a[i]);
        for(int l=Max-1; l>i; l--)
        {
            j=l-Max+i+1; k=B.a[l]; B.a[l]=0;
            while(j>=Max-size-(l-i)-4)
            {
                res=B.a[j];
                B.a[j]=k;
                k=res;
                j-=Max-i-1;
            }
            B.size++;
        }
        C=C+B;
    }
    return C;
}

bigint bigint::operator *(const int &b) 
{
    bigint C;
    int pere=0;
    for(int i=Max-1; i>=Max-size; i--)
    {
        C.a[i]=((a[i]*b)+pere)%10;
        pere=((a[i]*b+pere)/10);
    }    
    C.size=size;
    if (pere>0) 
    {
        C.size++;
        C.a[Max-size-1]=pere;
    }
    return C;
}

int main()
{
    
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n;
    in>>n;

    bigint c,b,a,ans;
    c="1";
    b="1";
    a="1";
    ans="0";
    if(n==0)
    {
        out<<0;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            c=c*b;
            b=b+a;
            ans=ans+c;
        }
        string c1;
        c1=string(ans);
        out<<c1;
    }
} 


