#include <iostream>
#include <queue>
using namespace std;

#define Max 30
#define INFINITY 1000000

struct point{
	int x;
	int y;
};

int n,m;

int c[Max+2][Max+2];
int a[Max+2][Max+2];

int checkPoint(int x,int y)
{
	if(x>0 && x<=n && y>0 && y<=m) return 1;
	return 0;
}

void add(queue<point> &b,int x,int y,int wh)
{
	int X=wh/3+x-1;
	int Y=wh%3+y-1;

	if(!checkPoint(X,Y)) return;

 	if(c[X][Y]>c[x][y]+a[X][Y])
	{
		c[X][Y]=c[x][y]+a[X][Y];
		point buffer;
		buffer.x=X;
		buffer.y=Y;
		b.push(buffer);
	}

}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);


	
	cin>>n>>m;

	for(int i=0; i<Max+2; i++)
		for(int j=0; j<Max+2; j++)
		{
			a[i][j]=INFINITY;
			c[i][j]=INFINITY;
		}


	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j];

	
	queue<point> b;
	point buffer;

	buffer.x=1;
	buffer.y=1;

	b.push(buffer);
	c[1][1]=a[1][1];

	while(!b.empty())
	{
		buffer=b.front();
		b.pop();

 		add(b,buffer.x,buffer.y,1);
 		add(b,buffer.x,buffer.y,3);
		add(b,buffer.x,buffer.y,5);
		add(b,buffer.x,buffer.y,7);
	}

	cout<<c[n][m];

} 
