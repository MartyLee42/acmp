#include <iostream>
#include <math.h>
using namespace std;

#define Max 200

struct tree{
	double x;
	double y;
	double r;
};

double opred(double a, double b, double c, double d)
{
	return a*d-b*c;
}

int n;

tree t[Max];

int check(double a,double b, double c,int i,int j)
{
	for(int k=0; k<n; k++)
	{
		if(k!=j && k!=i)
		{
			
			if(abs(a*t[k].x+b*t[k].y+c)<=t[k].r) return 0;

		}
	}
	return 1;
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>t[i].x>>t[i].y>>t[i].r;

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			double a,b,c;
			
			a=t[i].x-t[j].x;
			b=t[i].y-t[j].y;
			c=t[i].r+t[j].r;

			if(a==0)
			{
				b=(c/b);
				a=sqrt(1-b*b);
				c=t[i].r-a*t[i].x-b*t[i].y;
			}
			else
			{
				b/=a;
				c/=a;
				double D=sqrt(b*b-c*c+1);
				
				double bb=(c*b+D)/(b*b+1);
				a=c-b*bb;
				b=bb;
				c=t[i].r-a*t[i].x-b*t[i].y;
			}


			
			if(check(a,b,c,i,j)==1)
			{
				cout<<"NO";
				return 0;
			}

			a=t[i].x-t[j].x;
			b=t[i].y-t[j].y;
			c=t[i].r+t[j].r;

			if(a==0)
			{
				b=(c/b);
				a=sqrt(1-b*b);
				c=t[i].r-a*t[i].x-b*t[i].y;
			}
			else
			{
				b/=a;
				c/=a;
				double D=-sqrt(b*b-c*c+1);
				
				double bb=(c*b+D)/(b*b+1);
				a=c-b*bb;
				b=bb;
				c=t[i].r-a*t[i].x-b*t[i].y;
			}
			if(check(a,b,c,i,j)==1)
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
}
