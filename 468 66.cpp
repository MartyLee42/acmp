#include <iostream>
#include <string>

using namespace std;
__int64 C[5000][4];

#define Max 5000

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
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	__int64 N;
	
	
	for(__int64 i=0; i<5000; i++)
	{
		C[i][1]=i;
		C[i][2]=(i-1)*i/2;
		C[i][3]=(i-2)*(i-1)*i/6;
	}


	cin>>N;

	int a=3,b=2,c=1;

	while(N>C[a][3]) a++;
	N-=C[a-1][3];
	while(N>C[b][2]) b++;
	N-=C[b-1][2];
	c=N;

	bigint Ans,A,B;
    	Ans="1";
	A="1";
	B="1";

   	for(int i=1; i<a; i++)
        	Ans=Ans*2;
	for(int i=1; i<b; i++)
		A=A*2;
	for(int i=1; i<c; i++)
		B=B*2;

	Ans=Ans+B+A;
    	string c1;
    	c1=string(Ans);
    	cout<<c1;

}