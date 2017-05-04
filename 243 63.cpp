#include <iostream>
using namespace std;

#define Max 200
int r[Max][4];

#define MMM 100000000

int count(int i, int l)
{
	if(r[i][3]<l) return MMM;
	if(r[i][1]<=l) return l*r[i][2];
	if(r[i][1]<=r[i][3])
	{
		if(r[i][0]*l<r[i][1]*r[i][2]) return r[i][0]*l;
		return r[i][1]*r[i][2];
	}
	return l*r[i][0];
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	
	int a[Max][Max];
	for(int i=0; i<Max; i++)
	{
		for(int j=0; j<Max; j++)
		{
			a[i][j]=MMM;
		}
	}

	int n,l;
	
	cin>>n>>l;

	for(int i=0; i<n; i++)
		cin>>r[i][0]>>r[i][1]>>r[i][2]>>r[i][3];

	for(int i=0; i<n; i++)
		a[0][i]=0;

	for(int i=0; i<=l; i++)
		a[i][0]=count(0,i);

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=l; j++)
		{
			for(int k=0; k<=j; k++)
			{
				a[j][i]=min(a[j][i],a[j-k][i-1]+count(i,k));
			}
		}
	}
	int ans=MMM;
	for(int i=0; i<n; i++)
		ans=min(ans,a[l][i]);

	if(ans>=MMM) cout<<-1;
	else cout<<ans;

} 
