#include <fstream>

#include <queue>
using namespace std;

#define Max 2010

int n;
int a[Max],b[Max];

int answer(int Player, int num)
{
	int ans=-2;
	for(int i=2; i<=n; i++)
	{
		if(a[i]==num)
		{
			if(b[i]==-2)
			{
				if(Player==0)
				{
					if(ans!=-2)
						ans=min(ans,answer(1-Player,i));
					else
						ans=answer(1-Player,i);
				}
				else
					ans=max(ans,answer(1-Player,i));
			}
			else
			{
				if(Player==0)
				{
					if(ans!=-2)
						ans=min(ans,b[i]);
					else
						ans=b[i];
				}
				else
					ans=max(ans,b[i]);
			}
		}
	}
	return ans;
}

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	in>>n;

    memset(a,0,Max*sizeof(int));

	for(int i=0; i<Max; i++)
		b[i]=-2;

	char cc;
	
	for(int i=2; i<=n; i++)
	{
		in>>cc;
		if(cc=='N')
			in>>a[i];
		else
			in>>a[i]>>b[i];
	}	
	
	int aa=answer(1,1);
	if(aa==1)
		out<<"+1";
	else 
		out<<aa;
		
	
}
