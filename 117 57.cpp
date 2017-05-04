#include <fstream>
#include <algorithm>
using namespace std;

struct point
{
	int x;
	int y;
};

int compare(point a, point b)
{
	if(a.x>b.x) return 0;
	if(a.x==b.x && a.y>b.y) return 0;
	return  1;
}

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int n;

	point a[1010];

	in>>n;


	for(int i=0; i<n; i++)
		in>>a[i].x,
		in>>a[i].y;

	sort(a,a+n,compare);

	point b[1000];

	double ans=0;
	
	for(int i=0; i<n; i++)
	{
		 double x1=a[i].x,y1=a[i].y;
		 int m=i;

		 double tangens=-10000000000000;
		 for(int j=i+1; j<n ; j++)
		 {
            if((a[j].y-y1)>=(a[j].x-x1)*tangens) 
            {
                tangens=(a[j].y-y1)/(a[j].x-x1);
                m=j;
            }
         }
		 ans+=(a[m].x-x1)*(a[m].y+y1);
		 if(m==i) break;
		 i=m-1;
	}
	for(int i=0; i<n; i++)
	{
		 double x1=a[i].x,y1=a[i].y;
		 int m=i;

		 double tangens=10000000000000;
		 for(int j=i+1; j<n ; j++)
		 {
            if((a[j].y-y1)<=(a[j].x-x1)*tangens) 
            {
                tangens=(a[j].y-y1)/(a[j].x-x1);
                m=j;
            }
         }
		 ans-=(a[m].x-x1)*(a[m].y+y1);
		 if(m==i) break;
		 i=m-1;
	}
	


	
	out<<ans/2;
	
}