#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");
	
	int n,one=0;

	in>>n;
	char ch;
	int a[100010];
	int b[10];

	for(int i=0; i<n; i++)
	{
		in>>ch;
		if(ch=='1') one++;
		a[i]=1;
	}

	one--;
	

	int ii=0;

	if(one<0)
	{
		out<<0;
		return 0;
	}
	while(one>0)
	{
		if(one%2==1)
		{
			a[ii]=0;
		}

		one/=2;
		ii++;
	}

	for(int i=0; i<n; i++)
		a[i]=1-a[i];

	int pere=1;
	ii=0;
	while(pere>0 && ii<=n)
	{
		if(a[ii]==0) pere=0;
		a[ii]=(a[ii]+1)%2;
		ii++;
	}

	ii=n-1;

	while(a[ii]==0 && ii>0) ii--;

	for(int i=ii; i>=0; i--) out<<a[i];

	

} 

