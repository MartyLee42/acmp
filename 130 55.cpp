#include <fstream>
#include <queue>
using namespace std;

struct point{
	int x;
	int y;
	int nn;
};
int b[20][20];
queue<point> q;

bool cc(point p)
{
	if(p.x>0 && p.y<9 && p.x<9 && p.y>0) return true;
	return false;
}

void check(int x,int y, point p )
{
	point bb;
	bb=p;
	bb.x+=x;
	bb.y+=y;
	bb.nn++;

	if(cc(bb) && b[bb.x][bb.y]==0)
	{
		q.push(bb);
		b[bb.x][bb.y]=bb.nn;
	}
}


int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	char a[4];
	int x1,x2,y1,y2;
	in>>a;
	x1=a[0]-'a'+1;
	y1=a[1]-'0';

	in>>a;

	x2=a[0]-'a'+1;
	y2=a[1]-'0';

	memset(b,0,20*20*sizeof(int));

	point p;
	p.x=x1;
	p.y=y1;
	p.nn=1;

	q.push(p);
	b[p.x][p.y]=1;

	while(!q.empty())
	{
		p=q.front();
		q.pop();

		check(2,1,p);
		check(-2,1,p);
		check(2,-1,p);
		check(-2,-1,p);
		check(1,2,p);
		check(-1,2,p);
		check(1,-2,p);
		check(-1,-2,p);
	}
	if(b[x2][y2]%2==0) out<<"-1";
	else out<<(b[x2][y2]-1)/2;
	
}