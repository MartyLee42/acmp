#include <iostream>
using namespace std;

#define Max 10001
int a1,a2;

class bigint
{
public:
    bigint()
    {
        memset(a,0,Max*sizeof(a[0]));
        size=1;
    }

    bigint operator=(bigint &b);
    bigint operator=(char b[]);
    bigint operator/(int &b);
    
    __int64 operator%(int &b);

    int a[Max];
    int size;
};

bigint bigint::operator=(bigint &b)
{
    memcpy(a,b.a,b.size*sizeof(a[0]));
    size=b.size;
    return bigint();
}

bigint bigint::operator=(char b[])
{
    int i=0;
    while(b[i]>0)
    {
        if(b[i]>='A' && b[i]<='Z')
            a[i]=b[i]-'A'+10;
        else 
            a[i]=b[i]-'0';
        i++;
    }
    size=i;
    return bigint();    
}

__int64 bigint::operator%(int &b)
{
    __int64 ans=0;
    for(int i=0; i<size; i++)
    {
        ans=a1*ans+a[i];    
        ans%=b;
    }

    return ans;
}

bigint bigint::operator/(int &b)
{
    bigint A;
    __int64 x=0;
    int i=0;
    while(x<b && i<size)
    {
        x=x*a1+a[i];
        i++;
    }

    int j=1;
    A.a[0]=x/b;
    x%=b;
    for(i=i; i<size; i++)
    {
        x=x*a1+a[i];
        A.a[j]=x/b;
        x%=b;
        j++;
    }
    A.size=j;
    if(A.a[0]==0) A.size=0;
    return A;
}


int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    
    char a[1010];
    bigint c,d;

    cin>>a1>>a2>>a;
    c=a;
    int q[10000],i=0;

    while(c.size>0)
    {
        q[i]=c%a2;
        c=c/a2;
        i++;
    }
    for(int j=i-1; j>=0; j--)
    {
        char h;
        if(q[j]<10) h=q[j]+'0';
        else h='A'+q[j]-10;
        cout<<h;
    }
    
    
} 

