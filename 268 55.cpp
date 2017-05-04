#include <iostream>

using namespace std;

#define Max 5010

int b[Max][2];
char a[Max];

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int n,k;
	cin>>n>>k;
	
	
	cin>>a;

	
	for(int i=0; i<Max; i++)
		for(int j=0; j<2; j++)
			b[i][j]=0;

	int ans=n;
	for(int i=1; i<n; i++)
	{
		for(int j=i-1; j>=0; j--)
		{

			b[j][i%2]=b[j+1][(i-1)%2]+1;
			if(a[j]==a[i]) b[j][i%2]=b[j+1][(i-1)%2];

			if(b[j][i%2]<=k) ans++;
		}
	}
	cout<<ans;
 }
