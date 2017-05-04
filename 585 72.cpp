#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	long double a,b,N;
	cin>>N;

	a=log10(N);
	b=log10(N+1);
	long double aa,bb;

	__int64 m=0;
	for(int i=0; i<10000000; i++)
	{
		aa=(a+long double(i))/log10(2.0);
		bb=(b+long double(i))/log10(2.0);
		m=__int64(aa);
		if(aa<=m && m<bb)
		{
			cout<<m;
			break;
		}
		if(m+1<bb)
		{
			cout<<m+1;
			break;
		}

	}
}