#include <iostream>

using namespace std;

#define Max 110

struct shirt{
	int numOfShirts;
	int rem;
};


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	int a,b,c,k;
	cin>>a>>b>>c>>k;

	shirt s[Max][Max][Max];

	memset(s,0,Max*Max*Max*sizeof(s[0][0][0]));

	for(int i=0; i<=a; i++)
	{
		for(int j=0; j<=b; j++)
		{
			for(int l=0; l<=c; l++)
			{
				if(i>0)
				{
					int sh=s[i-1][j][l].numOfShirts;
					int rem=s[i-1][j][l].rem+1;

					if(rem>=k) 
					{
						rem=0;
						sh++;
					}
					if(s[i][j][l].numOfShirts<sh || (s[i][j][l].numOfShirts==sh && s[i][j][l].rem<rem))
					{
						s[i][j][l].numOfShirts=sh;
						s[i][j][l].rem=rem;
					}

				}
				if(j>0)
				{
					int sh=s[i][j-1][l].numOfShirts;
					int rem=s[i][j-1][l].rem+2;

					if(rem>=k) 
					{
						rem=0;
						sh++;
					}
					if(s[i][j][l].numOfShirts<sh || (s[i][j][l].numOfShirts==sh && s[i][j][l].rem<rem))
					{
						s[i][j][l].numOfShirts=sh;
						s[i][j][l].rem=rem;
					}
				}
				if(l>0)
				{
					int sh=s[i][j][l-1].numOfShirts;
					int rem=s[i][j][l-1].rem+3;

					if(rem>=k) 
					{
						rem=0;
						sh++;
					}
					if(s[i][j][l].numOfShirts<sh || (s[i][j][l].numOfShirts==sh && s[i][j][l].rem<rem))
					{
						s[i][j][l].numOfShirts=sh;
						s[i][j][l].rem=rem;
					}
				}
			}
		}
	}
	
	cout<<s[a][b][c].numOfShirts;
	
 }
