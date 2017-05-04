#include <fstream>
#include <math.h>
#include <string>
using namespace std;

#define Max 30

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
    bigint operator=( int b);
    
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
    size=b.size;
    return(bigint());
}

bigint bigint::operator =(int b)
{
    
    a[Max-1]=1;
    size=1;
    return(bigint());
}



bigint aa[2][105][105];

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    int n,k;
    in>>n>>k;

    
    memset(aa,0,2*105*105*sizeof(bigint));

    aa[1][1][1]=1;
    int i1,i2;
    i1=0;
    i2=1;
    for(int i=2; i<=2*n; i++)
    {
        for(int j=0; j<=2*n; j++)
        {
            for(int l=1; l<=2*n; l++)
            {
                aa[i1][j][l]=aa[i2][j+1][l];
                if(j==l && j>0)
                aa[i1][j][l]=aa[i1][j][l]+aa[i2][j-1][l-1];
                if(j<=l && j>0)
                aa[i1][j][l]=aa[i1][j][l]+aa[i2][j-1][l];
            }
        }
        swap(i1,i2);
    }
    string h=string(aa[0][0][k]);
    out<<h;
} 
