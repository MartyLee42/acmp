#include <fstream>
#include <math.h>
using namespace std;



int main()
{
	ifstream in("INPUT.txt");
	FILE *out=fopen("OUTPUT.txt","w");

	double x1,x2,y1,y2,x,y,r;
	
	in>>x1>>y1>>x2>>y2>>x>>y>>r;
	x1-=x;
	x2-=x;
	y2-=y;
	y1-=y;



	double l=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),
		   l1=sqrt(x1*x1+y1*y1),l2=sqrt(y2*y2+x2*x2);

	double m,n,b;

	m=(y2-y1);
	n=(x1-x2);
	b=x1*y2-y1*x2;

	
	int tr=1;


	if(m==0)
	{
		double dd=(r*r-(b*b/(n*n)));
		if(dd>0)
		{
			x=sqrt(dd);
			if(abs(abs(x1-x)+abs(x2-x)-abs(x2-x1))<0.0001) tr=0;
		}
	}
	else
	{
		b/=m;
		n/=m;

		double dd=n*n*b*b-(n*n+1)*(b*b-r*r);

		if(dd>0)
		{
			y=(b*n-sqrt(dd))/(n*n+1);
			x=b-n*y;
			if(abs(abs(x1-x)+abs(x2-x)-abs(x2-x1))<0.0001) tr=0;
		}
	}

	if(tr)
	{
		fprintf(out,"%.18f",l);
	}
	else
	{
		double a,a2,a3,a1,d1,d2;
		a=acos((l1*l1+l2*l2-l*l)/(2*(l1*l2)));
		d1=sqrt(l1*l1-r*r);
		a1=asin(d1/l1);
		d2=sqrt(l2*l2-r*r);
		a2=asin(d2/l2);
		a3=a-a1-a2;
		
		fprintf(out,"%.18f",(d1+d2+a3*r));
	}
}