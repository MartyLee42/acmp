#include <fstream> 
#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
public:
	int a;
	int b;
	int c;
};

point v[10000];

bool sr(point bb, point aa)
{
	if(aa.a>bb.a) return true;
	if(aa.a==bb.a && aa.b>bb.b) return true;
	if(aa.a==bb.a && aa.b==bb.b && aa.c>bb.c) return true;
	return false;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

	int n,m;
	in>>n>>m;

	int x[2001];
	
	for(int i=0; i<2001; i++)
	{	
		x[i]=100000000;
	}
	for(int i=0; i<m; i++)
	{
		in>>v[i].b>>v[i].a>>v[i].c;
		
		if(v[i].b==1)
			x[v[i].a]=v[i].c;

	}
	sort(v,v+m,sr);

	if(x[1]>0)
	x[1]=0;
	int l;
	for(int k=0; k<n; k++)
	{
		l=0;
		for(int i=1; i<=n ;i++)
		{
			while(v[l].a==i && l<m)
			{
				x[i]=min(x[i],x[v[l].b]+v[l].c);
				l++;
			}
		}
	}
	for(int i=0; i<n; i++) 
	{
		if(x[i+1]<10000000)
		out<<x[i+1]<<" ";
		else out<<30000<<" ";
	}


	
} 









