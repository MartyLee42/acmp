#include <fstream>
#include <queue>
using namespace std;

#define Max 44
#define INF 1000000000


int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int n,m;
	in>>n>>m;

	int r[Max],c[Max],a[Max][Max];

	memset(r,0,sizeof(r[0])*Max);
	memset(c,0,sizeof(c[0])*Max);
	memset(a,0,sizeof(a[0][0])*Max*Max);

	int s=n+m,t=n+m+1;
	for(int i=0; i<n; i++)
	{
		in>>r[i];
		a[s][i]=r[i];

	}
	for(int i=0; i<m; i++)
	{
		in>>c[i];
		a[i+n][t]=c[i];
	}

	int ans=0;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int h;
			in>>h;
			if(h>=0)
			{
				ans+=h;
				r[i]-=h;
				c[j]-=h;
				a[s][i]-=h;
				a[j+n][t]-=h;
			}
			else
			{
				a[i][j+n]=INF;
			}
		}
	}
	for(int i=0; i<Max; i++)
	{
		if(r[i]<0 || c[i]<0) 
		{
			out<<-1;
			return 0;
		}
	}
	
	int check[Max];

	for(;;)
	{
		queue<int> q;

		for(int i=0; i<n+m+2; i++)
			check[i]=-1;

		for(int i=0; i<n; i++)
			if(a[s][i]>0) 
			{
				q.push(i);
				check[i]=s;
			}
		int end=t;
		
		if(q.empty())
		{
			out<<ans;
			return 0;
		}
		for(;;)
		{
			int vert=q.front();
			if(a[vert][t]>0) 
			{
				check[t]=vert;
				break;
			}
			q.pop();
			for(int i=0; i<n+m; i++)
			{
				if(a[vert][i]>0 && check[i]==-1)
				{
					q.push(i);
					check[i]=vert;
				}
			}

			if(q.empty())
			{
				out<<ans;
				return 0;
			}
		}
		int min=INF;
		while(end!=s)
		{
			if(a[check[end]][end]<min) min=a[check[end]][end];
			end=check[end];
		}
		ans+=min;
		end=t;
		while(end!=s)
		{
			a[check[end]][end]-=min;
			a[end][check[end]]+=min;
			end=check[end];
		}
	}
}
