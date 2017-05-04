#include <iostream>
#include <math.h>


using namespace std;

int main()
{
	freopen("INPUT.txt","r",stdin);
	FILE *out =fopen("OUTPUT.txt","w");

	double r,l,d;
	cin>>r>>l>>d;

	double a=(4*asin(1.0)*r)/l;
	double aa=a*90/asin(1.0);

	double ans=0;

	if(aa<=90)
	{
		if(d>=l)
			ans=l*sin(a);
		else
			ans=l*cos(acos(sqrt(l*l-d*d)/l)-a);
	}
	if(90<aa && aa<=180)
	{
		if(d>=l*sqrt(2-2*cos(a))*sin(a/2))
			ans=l;
		else
			ans=l-l*sin(acos((d-l)/l)+a);
	}
	if(180<aa)
	{
		if(d>=2*l)
			ans=l*(1-cos(a/2));
		else
		{
			if(a-asin((d-l)/l)>2*asin(1.0))
				ans=2*l;
			else 
				ans=l*(1-cos(a));
		}
	}
	fprintf(out,"%.10f",ans);
}