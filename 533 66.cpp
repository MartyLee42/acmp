#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

int n; 
struct point{

	__int64 x;
	__int64 y;

};

point p[1510];
int ttt(point a,point b)
{
	if(a.x>b.x) return 1;
	if(a.x==b.x && a.y>=b.y) return 1;
	return 0;
}

unsigned __int64 sqr(__int64 a)
{
	unsigned __int64 aa;
	if(a<0) aa=-a;
	else
		aa=a;
	return aa*aa;
}

int f( __int64 x,__int64 y)
{
	point bb;
	bb.x=x;
	bb.y=y;
	int l=0,r=n;
	int m=0;
	while(true)
	{
		m=(l+r)/2;
	if (1-ttt(p[m],bb)) 
		r = m-1;
    else 
		if (1-ttt(bb,p[m]))
			l = m + 1;
		else
		{
			if(p[m].x==x && p[m].y==y)
				return 1;
			return 0;
		}
    if (l > r)
		return 0;
	}
}

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	in>>n;

	for(int i=0; i<n; i++)
		in>>p[i].x>>p[i].y;

	sort(p,p+n,ttt);


	__int64 a[1510];
	__int64 ans=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			a[j]=sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y);
		}
		sort(a,a+n);
		__int64 b=a[0];
		__int64 aaa=0;
		for(int j=1; j<n; j++)
		{
			if(b==a[j]) aaa++;
			else
			{
				ans+=aaa*(aaa+1)/2;
				aaa=0;
				b=a[j];
			}
		}
		ans+=aaa*(aaa+1)/2;
	}


	__int64 b=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			b+=f(2*p[i].x-p[j].x,2*p[i].y-p[j].y);
		}
	}
	out<<ans-(b-n+1)/2;
}