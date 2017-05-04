#include <fstream>
#include <algorithm>
using namespace std;

struct aa
{
	double b;
	int n;
};

bool s(aa a ,aa b)
{
	if(a.b>b.b) return true;
	return false;
}
double a[300], b[300];
aa ab[300];

double count(int n)
{
	double ans=0;

	int beg=0,end=n-1;

	double bn=0,en=0;

	while(beg<=end)
	{
		if(beg==end)
		{
			ans+=1/(1/a[ab[end].n]+1/b[ab[end].n]);
			return ans;
		}
		
		if (a[ab[beg].n]<b[ab[end].n])
		{
			double k=b[ab[end].n];
			b[ab[end].n]-=a[ab[beg].n];
			a[ab[end].n]*=b[ab[end].n]/k;
			ans+=a[ab[beg].n];
			beg++;
		}
		else
		{
			double k=a[ab[beg].n];
			a[ab[beg].n]-=b[ab[end].n];
			b[ab[beg].n]*=a[ab[beg].n]/k;
			ans+=b[ab[end].n];
			end--;
		}
		
	}
	return ans;
}

int main()
{
	ifstream in("INPUT.txt");
	FILE *out=fopen("OUTPUT.txt","w");
	
	int n;
	in>>n;
	

	for(int i=0; i<n; i++)
	{
		in>>a[i]>>b[i];	
		ab[i].b=a[i]/b[i];
		ab[i].n=i;
	}
	
	sort(ab,ab+n,s);

	fprintf(out,"%.8f\n",count(n));

	for(int i=0; i<n; i++)
		fprintf(out,"%d ",ab[i].n+1);
} 

