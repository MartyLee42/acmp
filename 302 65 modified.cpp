#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
#define Max 1010

struct arc{

	int first;
	int second;
	double weight;
};

int greater(arc a, arc b)
{
	if(a.weight>=b.weight) return 0;
	return 1;
}

double sqr(double a)
{
	return a*a;
}

int pp[Max]; //the parent tree
int size[Max];

// find the set
int Find(int a)
{
	if(pp[a]==a) return a;
	else 
	{
		pp[a]=Find(pp[a]);
		return pp[a];
	}
}



//merge (union) two sets
//we make a little modification
//this function will return 1 if two sets
//were merged and 0 if we didn't have to merge 'em 
int Union(int a,int b)
{
	int x=Find(a);
	int y=Find(b);

	if(x==y) return 0;

	if(size[x]<size[y]) swap(x,y);
	pp[y]=x;
	size[x]+=size[y];
	return 1;
}


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int n;

	cin>>n;

	double points[Max][2];
	arc a[Max*Max/2];


	// m - number of arcs
	int m=0;
	for(int i=0; i<n; i++)
	{
		cin>>points[i][0]>>points[i][1];

		for(int j=0; j<i; j++)
		{
			a[m].first=i;
			a[m].second=j;
			a[m].weight=sqr(points[i][0]-points[j][0])+sqr(points[j][1]-points[i][1]);
			m++;
		}
	}

	sort(a,a+m,greater);

	int num=0;
	int pos=0; //the arc we are trying to add

	//Creating n sets with one element in each
	for(int i=0; i<n; i++) 
	{
		pp[i]=i;
		size[i]=1;
	}

	if(n==0)
	{
		cout<<"0.00";
		return 0;
	}
	for(int i=0; i<m; i++)
	{
		if(Union(a[i].first,a[i].second)) num++;
		if(num==n-1) 
		{
			pos=i;
			break;
		}
	}

	double ans;
	ans=sqrt(double(a[pos].weight))+0.005;
    int mm=(int)ans;
    int h=(int)((100*ans));

    h=h-100*mm;

    cout<<mm;
	cout<<'.';
    if(h<10) cout<<'0';
    cout<<h;


 }
