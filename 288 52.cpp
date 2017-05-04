#include <iostream>
using namespace std;

int main()
{
	
	FILE *in, *out;
	in=fopen("INPUT.txt","r");
	out=fopen("OUTPUT.txt","w");

	char a[100000];
	int c=1;

	int b[5];
	memset(b,0,5);

	int i=0;
	do
	{
		a[i]=fgetc(in);
		
		if(a[i]==')'&& a[i-1]=='*') b[0]=i-1;
		if(a[i]=='}') b[1]=i;
		if(a[i]==39) b[2]=i;
		i++;
	}
	while(a[i-1]>0);
	
	i=0;
	int ans=0;
	while(a[i]>0)
	{
		if(a[i]=='/' && a[i-1]=='/')
		{
			while(a[i]!=10)
			{
				i++;
			}
			ans++;
			continue;
		}
		if(a[i]==39 && b[2]>i)
		{
			i++;
			while(a[i]!=39) i++;
			i++;
			continue;
		}
		if(a[i]=='{' && b[1]>i)
		{
			while(a[i]!='}') i++;
			ans++;
			continue;
		}
		if(a[i-1]=='(' && a[i]=='*' && b[0]>i)
		{
			while(a[i]!=')' || a[i-1]!='*') i++;
			ans++;
			continue;
		}
		i++;
	}
	fprintf(out,"%d",ans);
	
}