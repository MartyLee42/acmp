#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

#define Max 51000

struct grad
{
	double begin;
	double end;
};

int s(grad a,grad b)
{
	if(a.begin<b.begin) return 1;
	return 0;
}



int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int n;
	double x,y,x1,y1,r,l,a1,a2;
	double pii=57.295779513082320876798154814105;
	in>>n>>x>>y;

	grad angle[Max];
	for(int i=0; i<n; i++)
	{
		in>>x1>>y1>>r;
		l=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
		a1=acos((x1-x)/l)*pii;
		if(y1-y<0) a1=360-a1;
		a2=asin(r/l)*pii;
		angle[i].begin=a1-a2;
		angle[i].end=a1+a2;


	}

	sort(angle,angle+n,s);

	double aa=angle[0].end;
	for(int i=0; i<n; i++)
	{
		if(aa>=angle[i].begin)
			aa=max(aa,angle[i].end);
	}
	if(aa-angle[0].begin>=360) out<<"YES";
	else out<<"NO";
}