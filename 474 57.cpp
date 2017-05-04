#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 300

class bigint
{
public:
    bigint()
    {
        memset(a,0,2*Max);
        sign=0;
        size=0;
    };
    bigint operator-( bigint &b );
    bool operator >=(bigint &b );
	bool operator >(bigint &b);
    bigint operator+( bigint &b );
    bigint operator=( bigint &b);
    bigint operator=(char str[Max]);
    bigint operator*( bigint &b);
    bigint operator*(const short &b);
    
    public:
        short a[Max];
        short sign;
        int size;
};

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
 bool bigint::operator >(bigint &b)
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
        if (a[i]>b.a[i]) return true;
        return false;
     }
     return false;
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
        t.size=Max-j;
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

int main()
{
    char a[300];
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    in>>a;
   
	bigint n[500];
	n[0]="1";
	n[1].a[Max-1]=3;
	n[1].size=1;

	bigint b;
	b=a;
	int i;
	for(i=2; i<500; i++)
	{
		n[i]=n[i-1]*3;
		if(n[i]>=b) break;
	}

	int ans=0;
	
	for(int j=i-1; j>=0; j--)
	{
		if(b>n[j]) 
		{
			b=b-n[j];
		}
		if(b>n[j]) 
		{
			b=b-n[j];
			ans=1-ans;
		}
		
	}

	
	out<< ans;
} 