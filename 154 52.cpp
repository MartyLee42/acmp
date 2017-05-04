#include <iostream>
using namespace std;

__int64 c[1280];
__int64 dd[10];

__int64 sqcube(__int64 n)
{
	int a=0,b=1279,d;
	while(true)
	{
		d=(a+b)>>1;
		if(c[d]>n) b=d;
		else a=d;
		if(b-a<2) break;
	}
	return b;
}

int cube(__int64 n, __int64 num)
{
	
	if(n==0) return 1;
	if(n<0 || num==9) return 0;
	for(int i=sqcube(n)+5; i>=0; i--)
	{
		if(cube(n-c[i],num+1)==1)
		{
			dd[num]=i;
			return 1;
		}
		if(n>(9-num)*c[i]) break;
	}
	return 0;
}


int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);

	for(int i=0; i<1280; i++)
		c[i]=i*i*i;
	__int64 n;
	cin>>n;

	if(cube(n,1)==0) cout<<"IMPOSSIBLE";
	else
	{
		int aa=1;
		while(dd[aa]>0) 
		{
			cout<<dd[aa]<<" ";
			aa++;
		}
	}

} 
