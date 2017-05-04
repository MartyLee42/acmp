#include <iostream>

using namespace std;

#define Max 200009


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int n;
	char a[Max];

	cin>>n>>a;

	unsigned long long x=543437240216432943;
	unsigned long long stepen[Max];
	unsigned long long hash[Max][2];
	hash[0][0]=a[0];
	hash[n-1][1]=a[n-1];
	stepen[0]=1;

	for(int i=1; i<n; i++)
	{
		hash[i][0]=a[i]+hash[i-1][0]*x;
		hash[n-i-1][1]=a[n-i-1]+hash[n-i][1]*x;
		stepen[i]=stepen[i-1]*x;
	}
	stepen[n]=0;
	hash[n][1]=0;

	for(int i=0; i<n; i++)
	{
		int l=0, r=i+1;
		for(;;)
		{
			int m=(l+r)/2;
			if(hash[m][0]==hash[i-m][1]-hash[i+1][1]*stepen[m+1]) l=m;
			else r=m;

			if(abs(l-r)<=1)
			{
				l=-1;
				for(m=min(r+2,n-1); m>=max(l,0); m--)
				if(hash[m][0]==hash[i-m][1]-hash[i+1][1]*stepen[m+1]) 
				{
					l=m;
					break;
				}
				break;
			}
		}
		cout<<l+1<<" ";
	}
	
 }
