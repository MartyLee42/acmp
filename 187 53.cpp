#include <fstream>
using namespace std;





int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	__int64 a[30][30];
	memset(a,0,30*30*sizeof(__int64));
	
	int n;
	in>>n;
	a[0][0]=1;

	for(int i=0; i<2*n-1; i++)
	{
		for(int j=max(0,i-n+1); j<min(i+n,2*n-1); j++)
		{
			a[i+1][j+1]+=a[i][j];
			a[i+1][j]+=a[i][j];
			a[i][j+1]+=a[i][j];
		}
	}

	out<<a[2*n-1][2*n-1];
}