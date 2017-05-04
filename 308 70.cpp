#include <iostream>
#include <queue>
using namespace std;

#define Max 1009

struct point{

	int a;
	int b;
	int n;
};

int b[3];
queue<point> q;
int a[Max][Max];
int t;
void pere(int cc[], int from, int to, int n)
{
	point p;

	int bb[3];

	bb[0]=cc[0];
	bb[1]=cc[1];
	bb[2]=cc[2];

	int aa=bb[to];
	

	bb[to]+=bb[from];
	if(bb[to]>b[to]) bb[to]=b[to];
	bb[from]-=bb[to]-aa;

	if(a[bb[0]][bb[1]]==0)
	{
		p.a=bb[0];
		p.b=bb[1];
		p.n=n+1;

		q.push(p);
		a[bb[0]][bb[1]]=n+1;

		if(bb[0]==t) t=-n;
	}
	
}


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int s;
	
	memset(a,0,Max*Max*sizeof(a[0][0]));
	cin>>b[0]>>b[1]>>b[2]>>t;
	s=b[0];

	point c;
	c.a=s;
	c.b=0;
	c.n=1;

	
	q.push(c);
	a[s][0]=1;

	int bb[3];

	while(!q.empty())
	{
		point p=q.front();
		q.pop();

		bb[0]=p.a;
		bb[1]=p.b;
		bb[2]=s-bb[0]-bb[1];
		int n=p.n;

		pere(bb,0,1,n);
		pere(bb,0,2,n);
		pere(bb,1,0,n);
		pere(bb,1,2,n);
		pere(bb,2,0,n);
		pere(bb,2,1,n);

		if(t<0)
		{
			cout<<-t;
			return 0;
		}

	}
	cout<<"IMPOSSIBLE";
}