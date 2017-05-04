#include <iostream>
#include <math.h>
using namespace std;

__int64 max(__int64 a,__int64  b)
{
	if(a>b) return a;
	return b;
}

__int64 check(__int64 a, __int64 b, __int64 k)
{
	__int64 aa=1;
	while((b-k)%a==0)
	{
		aa++;
		b=(b-k)/a;
	}
	return aa;
}


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	__int64 n,k,nn;
	cin>>n>>k;

	nn=n-k;

	if(nn==0)
	{
		cout<<n+1<<" "<<1;
		return 0;
	}
	if(nn<0)
	{
		cout<<2<<" "<<0;
		return 0;
	}
	if(nn<=k)
	{
		cout<<2<<" "<<0;
		return 0;
	}
	
	__int64 ans=2,ans2=0;
	ans=n-k; ans2=1;
	__int64 aaa=__int64(sqrt(double(n)))+1;
	for(__int64 i=2; i<aaa; i++)
	{
		if(nn%i==0)
		{
			__int64 c;
			if(i>k)
			{
				c=check(i,nn/i,k);
				if(c>ans2)
				{
					ans2=c;
					ans=i;
				}
			}
			c=check(nn/i,i,k);
			if(c>ans2)
			{
				ans2=c;
				ans=nn/i;
			}
			

		}
	}

	cout<<ans<<" "<<ans2;
} 
