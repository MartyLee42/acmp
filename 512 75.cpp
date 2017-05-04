#include <iostream>
#include <queue>

using namespace std;

#define Max  11
#define Max2 3048576+1  //2^20+1 2^2*Max+1
#define Max3 2048		//2^Max


int main()
{

	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int n,m,k;
	__int64 ans=0;

	cin>>n>>m>>k;

	int mat[Max][Max];
	memset(mat,0,Max*Max*sizeof(mat[0][0]));

	int a[Max2];
	memset(a,0,Max2*sizeof(a[0]));
	a[0]=1;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			char h;
			cin>>h;
			if(h=='Y') mat[i][j]=1;
		}
	}

	queue<pair<int,int> > q;
	q.push(make_pair(0,0));

	while(!q.empty())
	{
		pair<int,int> h=q.front();
		q.pop();
		
		if(h.second!=0) a[h.first]/=h.second;
		if(h.second==k) 
		{
			ans+=a[h.first];
			continue;
		}

		int g[Max];
		memset(g,0,Max*sizeof(g[0]));

		int gg=Max3;
		
		for(int i=0; i<m; i++)
		{
			if((h.first & gg) !=0) g[i]=1;
			gg=gg<<1;
		}

		int bb=1;
		for(int i=0; i<n; i++)
		{
			int hh=h.first & bb;
			if( hh == 0) // boy available
			for(int j=0; j<m; j++) //finding a  girl
			{
				if(g[j]==0 && mat[i][j]==1) // new pair
				{
					int mask=( h.first | ( 1<<i | 1<<(j+Max) ) ); //adding a pair
					if(a[mask]==0)
					{
						q.push(make_pair(mask,h.second+1));
					}
					a[mask]+=a[h.first];
				}
			}
			bb=bb<<1;
		}


	}
	
	cout<<ans;
 }
