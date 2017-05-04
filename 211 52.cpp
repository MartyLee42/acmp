#include <fstream>
#include <queue>
using namespace std;

#define Max 100

struct p{
	int x;
	int y;
	int nn;
};
int h,w;

int b[Max][Max];
void mark(p a)
{
	b[a.x][a.y]=a.nn;
}

int cc(int x, int y)
{
	int ans=10000000;
	if(b[x+1][y]>0) ans=min(b[x+1][y],ans);
	if(b[x-1][y]>0) ans=min(b[x-1][y],ans);
	if(b[x][y+1]>0) ans=min(b[x][y+1],ans);
	if(b[x][y-1]>0) ans=min(b[x][y-1],ans);
	if(ans>=1000000) return 0;
	return ans;
}

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	
	in>>w>>h;
	int a[Max][Max];
	memset(a,0,Max*Max*sizeof(int));

	char hhh;
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			in>>hhh; 
			if(hhh=='X') a[i+1][j+1]=-1;
		}
	}
	int x1,x2,y1,y2;
	p point;
	while(true)
	{
		memcpy(b,a,Max*Max*sizeof(int));

		in>>x1>>y1>>x2>>y2;
		if(x1==0 && y1==0 && x2==0 && y2==0) break;
		point.x=y1;
		point.y=x1;
		point.nn=1;

		queue <p> q;
		q.push(point);

		mark(point);

		while(!q.empty())
		{
			p p2=q.front();
			q.pop();
			
			if( p2.x-1>=0 && b[p2.x-1][p2.y]==0)
			{
				p p3=p2;
				p3.x--;
				p3.nn++;
				mark(p3);
				q.push(p3);
			}

			if(p2.x<=h && b[p2.x+1][p2.y]==0)
			{
				p p3=p2;
				p3.x++;
				p3.nn++;
				mark(p3);
				q.push(p3);
			}
			
			if(p2.y-1>=0 && b[p2.x][p2.y-1]==0)
			{
				p p3=p2;
				p3.y--;
				p3.nn++;
				mark(p3);
				q.push(p3);
			}
			
			if( p2.y<=w && b[p2.x][p2.y+1]==0)
			{
				p p3=p2;
				p3.y++;
				p3.nn++;
				mark(p3);
				q.push(p3);
			}
			
			
		}
		out<<cc(y2,x2)<<"\n";
	}
}