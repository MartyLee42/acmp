#include <iostream>
using namespace std;

#define Max 110
#define INF 1000000

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	
	char a[Max];
	cin>>a;

	int n=0;
	while(a[n]>0) n++;

	int d[Max][Max]; //an array for dynamics
	memset(d,0,Max*Max*sizeof(d[0][0]));
	
	for(int i=1; i<n; i++)
		d[i][i]=1;

	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			int m=INF;
			char now=a[j-1];

			if(now!='(' && now!='[' && now!='{')
				for(int l=j-1; l>=j-i; l--)
				{
					if(abs(a[l-1]-now)<5 && a[l-1]!=now) //find the pair
						m=min(m,d[j-i][l-1]+d[l+1][j-1]);
				}
			for(int l=j; l>=j-i; l--)
				m=min(m,d[j-i][l-1]+d[l][j-1]+1);

			d[j-i][j]=m;
		}
	}
	cout<<d[1][n];
 }
