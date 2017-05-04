#include <iostream>
#include <math.h>
using namespace std;

#define Max 10

int desk[Max][Max];
int n;
__int64 ans=0;

void add(int x,int y,int a)
{
	for(int i=x+1; i<n; i++)
	{
		desk[i][y]+=a;

		if(y+i-x<n) 
			desk[i][y+i-x]+=a;
		if(y-i+x>=0) 
			desk[i][y-i+x]+=a;
	}
	if(x+1<n && y-2>=0) desk[x+1][y-2]+=a;
	if(x+1<n && y+2<n) desk[x+1][y+2]+=a;
    if(x+2<n && y-1>=0) desk[x+2][y-1]+=a;
	if(x+2<n && y+1<n) desk[x+2][y+1]+=a;

}


void count(int x,int k)
{
	if(k==0) 
	{
		ans++;
		return;
	}
	if(k==1)
	{
		for(int i=x; i<n; i++)
			for(int j=0; j<n; j++)
				if(desk[i][j]==0) ans++;
		return;
	}

	for(int i=x; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(desk[i][j]==0)
			{
				add(i,j,1);
				count(i+1,k-1);
				add(i,j,-1);
			}
		}
	}
}



int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int k;
	cin>>n>>k;

	memset(desk,0,Max*Max*sizeof(desk[0][0]));

	count(0,k);
	
	cout<<ans;

} 
