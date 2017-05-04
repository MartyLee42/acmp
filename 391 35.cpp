#include <fstream>
using namespace std;

int c(int x, int m, int a)
{
	int s=0,n=1;
	while(a)
	{
		s+=n*(a%10);
		n*=x;
		a/=10;
		n%=m;
		s%=m;
	}

	return s;
}

int main()
{
	ifstream n("INPUT.txt");
	ofstream o("OUTPUT.txt");

	

	int x,m,l,v,j;
	n>>x>>m>>l>>v;

	char a[10];

	for(j=0; j<99999;j++)
		if(c(x,m,j)==v) break;

	while(j>0)
	{
		o<<j%10;
		j/=10;
		l--;
	}

	for(j=0; j<l; j++)
		o<<0;
	
}