#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#define Max 80000
#define MaxN 20

__int64 GCD(__int64 x, __int64 y)
{
	while(x>0)
	{
		y=y%x;
		swap(x,y);
	}
	return y;
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	int n,nn,k;

	__int64 a[Max][MaxN];	//dynamics array
	__int64 b[MaxN];		//numbers
	__int64 mat[MaxN][MaxN];//which can stand together

	memset(a,0,Max*MaxN*sizeof(a[0][0]));
	memset(mat,0,MaxN*MaxN*sizeof(mat[0][0]));

	

	cin>>n>>nn>>k;
	for(int i=0; i<n; i++)
		cin>>b[i];

	for(int i=0; i<MaxN; i++)
		if(b[i]>=k)
			a[0][i]=1;

	sort(b,b+n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(GCD(b[i],b[j])>=k)
				mat[i][j]=1;
		}
	}

	int n2=1;

	queue<pair<int,int> > q;
	pair<int,int>h;

	int stepen[MaxN];
	stepen[0]=1;
	for(int i=1; i<n; i++)
		stepen[i]=stepen[i-1]*2;

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(mat[i][j]==1)
			{
				h.first=stepen[i];
				h.second=j;
				q.push(h);

				h.first=stepen[j];
				h.second=i;
				q.push(h);

				a[stepen[i]][j]=1;
				a[stepen[j]][i]=1;
				
			}
		}
	}

	

	while(!q.empty())
	{
		pair<int,int> now=q.front();
		q.pop();

		int mask=now.first;
		int num=now.second;

		int newMask=stepen[num]|mask;
		for(int j=0; j<n; j++)
		{
			if((newMask|stepen[j])!=newMask)
			{
				if(mat[j][num]==1)
				{
					if(a[newMask][j]==0)
					{
						h.first=newMask;
						h.second=j;
						q.push(h);
					}
					a[newMask][j]+=a[mask][num];
				}
			}
		}
	}
	
	int used[MaxN];
	memset(used,0,MaxN*sizeof(used[0]));

	int mask=1;
	//creating mask 
	//1-used
	//0-not used
	for(int i=1; i<=n; i++)
		mask*=2;

	mask-=1;

	//may be written in recursion
	int previous=0;
	int numOf=0;
	int ans[MaxN];
	memset(ans,0,MaxN*sizeof(ans[0]));

	for(int i=0; i<n; i++)
	{
		
		int maskChange=1;
		for(int j=0; j<n; j++)
		{
			if(used[j]==0 && GCD(previous,b[j])>=k) //not used
			{
				if(~(~mask|maskChange)!=mask)
				{
					int newMask=~(~mask|maskChange);
 					if(a[newMask][j]+numOf>=nn)
					{
						mask=~(~mask|maskChange);
						ans[i]=b[j];
						previous=ans[i];
						used[j]=1;
						break;
					}
					else
						numOf+=a[newMask][j];
				}
			}
			maskChange*=2;
		}
		if(numOf>nn) break;
	}

	if(n==1 && nn<=1)
		cout<<b[0];
	else
		if(ans[n-1]<=0) cout<<-1;
		else
			for(int i=0; i<n; i++)
				cout<<ans[i]<<" ";

 } 
