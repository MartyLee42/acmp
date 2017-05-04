#include <iostream>
#include <math.h>
using namespace std;
double S;

int t(double a,double b, double c)
{
	if(b*b+c*c-a*a<0) return 1;
	return 0;
}

double q(double a,double b, double c)
{
	if(t(a,b,c))
	{
		double m=(2*a*b*b)/(b*b+a*a-c*c);
		m*=m;
		m=sqrt(m-b*b);

		double m1=(2*a*c*c)/(c*c+a*a-b*b);
		m1*=m1;
		m1=sqrt(m1-c*c);

		double ans=(max(m*b/2,m1*c/2));

		return ans;
	}

	if(t(b,a,c)) return q(b,a,c);
	if(t(c,a,b)) return q(c,a,b);

	double ans=max(S/a*sqrt(c*c-(2*S/a)*(2*S/a)),S/a*sqrt(b*b-(2*S/a)*(2*S/a)));
	if((a*a+b*b-c*c)/(a*b)<sqrt(2.0) && ((a*a+c*c-b*b)/(a*c)<sqrt(2.0)))
	ans=max(ans,a*a/4);
	return ans;
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	FILE *out =fopen("OUTPUT.txt","w");

	double a,b,c;
	cin>>a>>b>>c;
	double ans=0;

	double p=(a+b+c)/2;
	S=sqrt(p*(p-a)*(p-b)*(p-c));

	ans=max(q(a,b,c),max(q(b,a,c),q(c,b,a)));

	fprintf(out,"%.10f",ans);
}