#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

#define Max 1200
#define MaxN 80
#define MAX 800000000.0 


int sqr(int x)
{
	return x*x;
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int n;
	cin>>n;

	double a[Max][Max];
	int point[Max][2]; 
	for(int i=0; i<n; i++)
		cin>>point[i][0]>>point[i][1];
 
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			a[i][j]=sqr(point[i][0]-point[j][0]) +sqr(point[i][1]-point[j][1]);

	double left=0.0, right=MAX;
	int b[Max];
	
	for(int i=0; i<MaxN; i++)
	{
		memset(b,0,Max*sizeof(b[0]));
		double ans=(left+right)/2;
		bool out=false;

		queue<int> c;

		for(int j=0; j<n ;j++)
		{
			if(b[j]!=0) continue;
			c.push(j);
 			b[j]=1;

			while(!c.empty())
			{
				int m=c.front();
				c.pop();
				for(int k=0; k<n; k++)
				{
					if(k==m) continue;
					if(a[m][k]<ans)
					{
						if(b[k]==0)
						{
							b[k]=3-b[m];
							c.push(k);
						}
						else
						{
							if(b[k]==b[m])
								out=true;
						}
					}
					if(out) break;
				}
				if(out) break;
			}

		}
		

		if(out)
			right=ans;
		else
			left=ans;
	}
	fprintf(stdout,"%.18f\n",sqrt(left)/2);
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
} 
