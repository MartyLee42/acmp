#include <fstream>
#include <algorithm>

using namespace std; 

void main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int n;
	in>>n;

	int a[1010];
	memset(a,0,1010*sizeof(a[0]));
	for(int i=0; i<2*n; i++)
		in>>a[i];

	a[2*n]=0;
	a[2*n+1]=1000000000;

	sort(a,a+2*n+2);
	int ans=0;
	int white=1;
	int now=0;
	int l=0;

	for(int i=0; i<=2*n+1; i++)
	{
		if(a[i]==a[i+1])
		{
			a[i]=1000000001;
			a[i+1]=1000000001;
			l++;
		}
	}
	sort(a,a+2*n+2);
	n-=l;

	for(int i=0; i<=2*n+1; i++)
	{
		now=a[i+1]-a[i];
		ans=max(white*now,ans);
		white=(white+1)%2;
	}
	out<<ans;

}