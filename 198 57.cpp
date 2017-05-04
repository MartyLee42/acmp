#include <fstream>
#include <algorithm>
using namespace std;
int n;
double a[110][110];

void addRows( int x, int y, double q)
{
	for(int i=0; i<n+1; i++) a[x][i]+=q*a[y][i];
}
void multiplyRow(int x, double q)
{
	for(int i=0; i<n+1; i++) a[x][i]*=q;
}
void changeRows(int x, int y)
{
	for(int i=0; i<n+1; i++) swap(a[x][i],a[y][i]);
}

int round(double b)
{
	if(b<-0.5) return int(b-0.5);
	if(b>0.5) return int(b+0.5);
	return 0;
}



int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	
	
	in>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n+1; j++)
			in>>a[i][j];

	for(int i=0; i<n; i++)
	{
		if(a[i][i]==0)
		{
			int j=i;
			while(a[j][i]==0) j++;
			changeRows(i,j);
			
		}
		multiplyRow(i,1/a[i][i]);
		
		for(int j=i+1; j<n; j++)
			addRows(j,i,-a[j][i]);
	}
	
	for(int i=n-1; i>=0; i--)
	{
		for(int j=0; j<i; j++)
			addRows(j,i,-a[j][i]);
	}
	
	for(int i=0; i<n; i++)
		out<<round(a[i][n])<<" ";

}