#include <iostream>
using namespace std;

int p[500100];

int main()
{
	FILE *in,*out;
	in=fopen("INPUT.txt","r");
	out=fopen("OUTPUT.txt","w");
	int n;
	fscanf(in,"%d",&n);
	
	for(int i=0; i<500100; i++)
		p[i]=0;

	for(int i=2; i<500100; i++)
		for(int j=2*i; j<500100; j+=i)
			p[j]=1;
	while(true)
	{
		int begin=1;
		
		for(int i=n+1; i<500100; i++)
		{
			if(p[i]==0)
			{
				begin=i;
				break;
			}
		}
		for(int i=n; i>begin>>1; i--)
		{
			fprintf(out,"%d %d\n",i,begin-i);
		}
		n=begin -n-1;
		if(n<2) break;
	}
}