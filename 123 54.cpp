#include <fstream>

using namespace std;

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int a[200][200];
	memset(a,0,200*200*sizeof(a[0][0]));
	a[0][1]=1;

	int n;
	char b[100];
	in>>b;
	if(b[0]==')') 
	{
		out<<0;
		return 0;
	}
	int l=0;
	while(b[l]>0) l++;
	for(int i=1; i<l; i++)
	{
		if(b[i]=='(')
		{
			for(int j=1; j<200; j++)
				a[i][j]=a[i-1][j-1];
			continue;
		}
		if(b[i]==')')
		{
			for(int j=0; j<199; j++)
				a[i][j]=a[i-1][j+1];
			continue;

		}
		for(int j=1; j<200; j++)
			a[i][j]+=a[i-1][j-1];
		for(int j=0; j<199; j++)
			a[i][j]+=a[i-1][j+1];
	}
	out<<a[l-1][0];
}












