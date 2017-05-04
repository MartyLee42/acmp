#include <fstream>
#include <queue>
using namespace std;

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int n,m;
	in>>n>>m;


	int p[101][101];
	memset(p,0,101*101*sizeof(int));

	for(int i=0; i<m; i++)
	{
		int a,b;
		in>>a>>b;
		p[a][b]=1;
		p[b][a]=1;
	}

	int c[102];
	memset(c,0,102*sizeof(int));

	queue<int> q;

	int ii=1;
	int cc;
	while(ii<n)
	{
		ii=1;

		while(c[ii]!=0) ii++;
		if(ii==n) break;

		q.push(ii);
		c[ii]=1;
		
		while(!q.empty())
		{
			int x=q.front();
			q.pop();

			cc=c[x];
			if(cc==1)cc=2;
			else cc=1;

			for(int i=1; i<=n; i++)
			{
				if(p[i][x]==1)
				{
					if(c[i]==0)
					{
						c[i]=cc;
						q.push(i);
					}
					else
					{
						if(c[i]!=cc)
						{
							out<<"NO";
							return 0;
						}
					}
				}
			}
		}
	}
	out<<"YES";
}