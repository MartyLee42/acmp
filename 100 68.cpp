#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 100

class bigint
{
public:
    bigint()
    {
        memset(a,0,2*Max);
        size=0;
    };
    operator string();
    bigint operator+( bigint &b );
    bigint operator=( bigint &b);
    bigint operator=( string &str);
    bigint operator=(char str[Max]);
    bigint operator*( bigint &b);
    bigint operator*(const short &b);
    
    private:
        short a[Max];
        int size;
};

 bigint::operator string()
{
    int k=0,j=0;
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
    size=b.size;
    return(bigint());
}

bigint bigint::operator =(string &str)
{
    int len=str.length();
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


bigint bigint::operator *(const short &b) 
{
    bigint C1;
    int pere=0;
    for(int i=Max-1; i>=Max-size; i--)
    {
        C1.a[i]=((a[i]*b)+pere)%10;
        pere=((a[i]*b+pere)/10);
    }    
    C1.size=size;
    if (pere>0) 
    {
        C1.size++;
        C1.a[Max-size-1]=pere;
    }
    return(C1);
}
bigint bigint::operator*(bigint &b)
{
    bigint C1,D;
    int s;
    s=size;
    for (int i = Max-1; i >= Max-s; i--)
    {
        D=(b*a[i]);
        memcpy(&D.a[i-D.size+1],&D.a[Max-D.size],2*D.size);
        memset(&D.a[i+1],0,2*(Max-i-1));
        D.size+=Max-i-1;
        C1=C1+D;
    }
    return(C1);
}

bigint a[2][600];  

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    int n;
    in>>n;
    n/=2;
    char f[100];
    f[0]='1';
    f[1]=0;

    bigint q;
    q=f;

    for(int y=0; y<10; y++)
    {
        a[0][y]=q;
    }
    f[0]='0';
    q=f;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=9*i+9; j++)
        {
            a[i%2][j]=q;
            for(int k=j; (k>=j-9 && k>=0); k--)
                a[i%2][j]=a[i%2][j]+a[(i+1)%2][k];

        }
    }

    string str;

    bigint c;
    for(int i=0; i<=n*9; i++)
    {
        c=c+(a[(n+1)%2][i]*a[(n+1)%2][i]);
    }

    str=string(c);
    out<<str;
    
} 



