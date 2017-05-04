#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 1500

class bigint
{
public:
    bigint()
    {
        memset(a,0,2*Max);
        sign=0;
        size=0;
    };
    bigint operator+( bigint &b );
    bigint operator=(__int64 &b);
    bigint operator=( bigint &b);
    bigint operator=(char str[Max]);
    bigint operator*( bigint &b);
    bigint operator*(const short &b);
    
    public:
        short a[Max];
        short sign;
        int size;
};




bigint bigint::operator=(__int64 &b)
{
    
    size=0;
    __int64 bb=b;
    while(bb>0)
    {
        size++;
        bb/=10;
    }
    bb=b;
    for(int i=Max-1; i>=Max-size; i--)
    {
        a[i]=bb%10;
        bb/=10;
    }
    return(bigint());
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
   

__int64 q[50][50];
__int64 q1[50][50];

__int64 v(int a, int b)
{
    if(a<b) return v(b,a);
    if(!(q[a][b]==0)) return q[a][b];
    if(a>b && a>24) return v(a-1,b);
    if(a==1 && b==1) return 2;
    if(a==0 || b==0) return 1;
    __int64 ans;
    ans=(v(a-1,b)+v(a,b-1));
    q[a][b]=ans;
    return ans;
}

__int64 vo(int a, int b)
{
    if(a<b) return vo(b,a);
    if(!(q1[a][b]==0)) return q1[a][b];
    if(a>b && a>14) return vo(a-1,b);
    if(a==1 && b==1) return 2;
    if(a==0 || b==0) return 1;
    __int64 ans;
    ans=(vo(a-1,b)+vo(a,b-1));
    q1[a][b]=ans;
    return ans;
}
    
int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;
    __int64 y=1;
    in>>n;

    bigint ans,t;
    ans=y;

    char h;
    int a,b;
    for(int i=0; i<3; i++)
    {
        in>>a>>h>>b;
        y=v(a,b);
        t=y;
        ans=ans*t;
    }
    if(n>3)
{
in>>a>>h>>b;
        y=v(a,b);
        t=y;
        ans=ans*t;
}


    if(n==5)
    {
        in>>a>>h>>b;
        y=vo(a,b);
        t=y;
        ans=ans*t;
    }

    int j=0;
    for(j=0; j<Max; j++)
    {
        if(ans.a[j]!=0) break;
    }
    for(j=j;j<Max; j++) out<<ans.a[j];

}



