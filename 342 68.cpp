#include <fstream>
#include <math.h>
using namespace std;

double eps=1E-8;

struct point{
	double x;
	double y;
};
struct line{

	double a;
	double b;
	double c;
};

double opred(double a,double b,double c,double d)
{
	return a*d-b*c;
}

int main()
{
	ifstream in("INPUT.txt");
	FILE *out;
	out=fopen("OUTPUT.txt","w");
	
	int n;

	in>>n;

	point a[10];
	line l[10];
	for(int i=0; i<n; i++)
		in>>a[i].x>>a[i].y;
    
	for(int i=0; i<n; i++)
	{
		double x1,x2,y1,y2;
		x1=a[i].x-a[(i+1)%n].x;
		x2=a[(i+2)%n].x-a[(i+1)%n].x;
		y1=a[i].y-a[(i+1)%n].y;
		y2=a[(i+2)%n].y-a[(i+1)%n].y;

		l[i].a=y1/(sqrt(x1*x1+y1*y1))+y2/(sqrt(x2*x2+y2*y2));
		l[i].b=-x1/(sqrt(x1*x1+y1*y1))-x2/(sqrt(x2*x2+y2*y2));
		l[i].c=(a[(i+1)%n].x*l[i].a+a[(i+1)%n].y*l[i].b);
	}
	double x=-1E20,y=-1E20;
	for(int i=0; i<n; i++)
	{
		double xx,yy;
		double d=opred(l[i].a,l[i].b,l[(i+1)%n].a,l[(i+1)%n].b);
		xx=opred(l[i].c,l[i].b,l[(i+1)%n].c,l[(i+1)%n].b);
		yy=opred(l[i].a,l[i].c,l[(i+1)%n].a,l[(i+1)%n].c);
		if(d==0)
		{
			fprintf(out,"NO");
			return 0;
		}
		xx/=d;
		yy/=d;
		if(x==-1E20) 
		{
			x=xx;
			y=yy;
		}
		if(x-xx>eps || y-yy>eps)
		{
			fprintf(out,"NO");
			return 0;
		}
	}
	double r;
	double aa,bb,cc;
	aa=(a[1].y-a[0].y);
	bb=-(a[1].x-a[0].x);
	cc=-a[0].x*a[1].y+a[0].y*a[1].x;
	r=abs(aa*x+bb*y+cc)/(sqrt(aa*aa+bb*bb));
	fprintf(out,"YES\n%.3f %.3f %.3f",x+eps,y+eps,r+eps);	

} 