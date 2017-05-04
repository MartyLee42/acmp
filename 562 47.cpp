#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

#define Max 300
#define MAX 1000000
int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int a[Max][Max];
	
	int n,m;

	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<n ;j++)
			a[i][j]=MAX;

	for(int i=0; i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x-1][y-1]=min(0,a[x-1][y-1]);
		a[y-1][x-1]=min(1,a[y-1][x-1]);
		
	}

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				a[i][j]=min(a[i][k]+a[k][j],a[i][j]);

	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(a[i][j]<MAX/2)
				ans=max(ans,a[i][j]);
	cout<<ans;
} 
