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
        sign=0;
        size=0;
    };
    operator string();
    bigint operator-( bigint &b );
    bigint operator+( bigint &b );
    bigint operator=( bigint &b);
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



int main()
{
    bigint a[10][100];
    int n;
    
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    in>>n;

    char a1[10];
    a1[0]='1';
    a1[1]=0;
    for(int i=0; i<10; i++)
    {
        a[i][0]=a1;
    }

    a1[0]='0';
    
    a[8][0]=a1;
    a[0][0]=a1;

    for(int i=1; i<100; i++)
    {
        a[1][i]=a[8][i-1]+a[6][i-1];
        a[2][i]=a[7][i-1]+a[9][i-1];
        a[3][i]=a[4][i-1]+a[8][i-1];
        a[4][i]=a[9][i-1]+a[0][i-1]+a[3][i-1];
        a[6][i]=a[7][i-1]+a[0][i-1]+a[1][i-1];
        a[7][i]=a[6][i-1]+a[2][i-1];
        a[8][i]=a[1][i-1]+a[3][i-1];
        a[9][i]=a[2][i-1]+a[4][i-1];
        a[0][i]=a[4][i-1]+a[6][i-1];
    }
    bigint C;
    C=a1;
    for(int i=0; i<10; i++)
    {
        C=C+a[i][n-1];
    }
    string s;
    s=string(C);
    out<<s;
} 



