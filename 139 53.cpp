#include <fstream> 
#include <iostream>
#include <algorithm>
#include <queue>
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

int f(int m,int aa)
{
	int i=0;
	while(v[i].a<aa) i++;
	return i;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

	int n,m;
	int nn[2001];
	memset(nn,0,8004);
	in>>n>>m;

	int x[2001];
	
	for(int i=0; i<2001; i++)
	{	
		x[i]=-100000000;
	}
	for(int i=0; i<m; i++)
	{
		in>>v[i].b>>v[i].a>>v[i].c;
		
		if(v[i].b==1)
			x[v[i].a]=v[i].c;

	}
	sort(v,v+m,sr);

	if(x[1]<0)
	x[1]=0;
	int l;
	for(int k=0; k<n; k++)
	{
		l=0;
		for(int i=1; i<=n ;i++)
		{
			while(v[l].a==i && l<m)
			{
				if(x[v[l].b]>-10000000)
				x[i]=max(x[i],x[v[l].b]+v[l].c);
				l++;
			}
		}
	}
	l=0;
	for(int i=1; i<=n ;i++)
	{
		while(v[l].a==i && l<m)
		{
			if(x[v[l].b]>-10000000)
			{
				if(x[i]<x[v[l].b]+v[l].c)
				{
					x[i]=1000000000;
				}
			}
			l++;
		}
	}

	nn[n]=1;
	queue <int> line;
	line.push(n);
	while(!line.empty())
	{
		int y=line.front();
		line.pop();
		nn[y]=1;
		int q=f(m,y);
		while(v[q].a==y)
		{
			if(nn[v[q].b]==0)
				line.push(v[q].b);
			q++;
		}

	}
	
	

	for(int i=1; i<=n; i++)
	{
		if(x[i]>100000000 && nn[i]==1)
		{
			out<<":)";
			return 0;
		}
	}
	if(x[n]>-1000000) out<<x[n];
	else out<<":(";
	


	
} 









