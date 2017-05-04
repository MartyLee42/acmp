#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 1700

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
    bigint operator^(const int &b);
    bigint operator-( bigint &b );
    bool operator >=(bigint &b);
    bigint operator+( bigint &b );
    bigint operator=( bigint &b);
    bigint operator=( string &str);
    bigint operator=(char str[Max]);
    bigint operator*( bigint &b);
    bigint operator*(const short &b);
    
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

 bool bigint::operator >=(bigint &b)
 {
     if (b.size>size) return false;
     if (b.size<size) return true;
     int i;
    
     for(i=Max-size; i<Max; i++)
     {
        if(a[i]!=b.a[i]) 
        {
            break;
        }
     }
     if(i!=Max)
     {
        if (a[i]>=b.a[i]) return true;
        return false;
     }
     return true;
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
bigint bigint::operator-(bigint &b)
{
    bigint t;
    int perenos=0,k=0;
    memcpy(&t.a,&a,2*Max);
    t.size=size;
    if(t>=b) 
    {
        for(int i=Max-1; i>=Max-t.size; i--)
        {
            perenos = perenos+t.a[i]-b.a[i]+10;
            t.a[i] = perenos % 10;
            if(perenos < 10) perenos=-1; else perenos=0;
        }
        int j=0;
        while(t.a[j]==0) j++;
        t.size=Max-j+1;
    }
    else
    {
        t=b-t;
        t.sign=-1;
        if(t.sign==1 && t.a[Max-1]==0) t.sign=0;
    }
    return t;
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



bigint bigint::operator ^(const int &b)
{
    int k=b;
    bigint t,C;
    C="1";
    memcpy(&t.a,&a,2*Max);
    t.size=size;
    while (k) 
    {
        if (k & 1) 
        C = C * t;
        t = t * t;
        k >>= 1;
    }
    return C;
}

    

int main()
{
    int a1;
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    in>>a1;
    bigint c1;
    c1="45";
    
    c1=c1^a1;
    string s;
    s=string(c1);
    out<<s;
} 


