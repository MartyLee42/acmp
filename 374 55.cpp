#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h> 
using namespace std;

struct point
{
	double x;
	double y;
};

bool sr(point a,point b)
{
	if(a.x>b.x) return false;
	if(a.x==b.x && a.y>b.y) return false;
	return true;
}


int main()
{
    freopen("INPUT.txt","r",stdin);
	FILE *out = fopen("OUTPUT.txt","w");

	int n;
	point p[1010];
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>p[i].x>>p[i].y;

	sort(p, p+n,sr);
	int ll=0;
	int begin1=1, begin2=1;
	while(p[ll].x==p[0].x) ll++;
	begin1=ll;
	begin2=ll;
	double ans=abs(p[0].y-p[ll-1].y);
	
	
	double x1=p[0].x,y1=p[ll-1].y,x2=x1,y2=p[0].y;
	ll=0;
	while(p[n-ll-1].x==p[n-1].x)ll++;
	ans+=abs(p[n-ll].y-p[n-1].y);
	

	while(true)
	{
		int l=0;
		double tangens=-10000000000000;
		for(int j=begin1; j<n ; j++)
		{
			if((p[j].y-y1)>=(p[j].x-x1)*tangens) 
			{
				tangens=(p[j].y-y1)/(p[j].x-x1);
				l=j;
			}
		}
		begin1=l;
		ans+=sqrt((p[l].x-x1)*(p[l].x-x1)+(p[l].y-y1)*(p[l].y-y1));
		x1=p[l].x;
		y1=p[l].y;
		if(p[begin1].x==p[n-1].x) break;
		if(begin1>=n-1) break;
		while(x1==p[begin1].x)begin1++;
	}
	while(true)
	{
		int l=0;
		double tangens2=100000000000000;
		for(int j=begin2; j<n; j++)
		{
			if((p[j].y-y2)<=(p[j].x-x2)*tangens2) 
			{
				tangens2=(p[j].y-y2)/(p[j].x-x2);
				l=j;
			}
		}
		begin2=l;
		ans+=sqrt((p[l].x-x2)*(p[l].x-x2)+(p[l].y-y2)*(p[l].y-y2));
		x2=p[l].x;
		y2=p[l].y;
		if(p[begin2].x==p[n-1].x) break;
		if(begin2>=n-1) break;
		while(x2==p[begin2].x) begin2++;
	}
			
	fprintf(out,"%.4f",ans);
    
 } 

