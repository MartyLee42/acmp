#include <string>
#include <fstream>
using namespace std;

char l[100010];
__int64 a[30][3];

__int64 count(int b) 
{
	__int64 ans=0;
	for(int i=0; i<30; i++)
	{
		ans+=a[i][0]*(abs(i-b));
	}
	return ans;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n;
	in>>n; 
	memset(a,0,60*3*sizeof(int));
	
	for(int i=0; i<n; i++)
	{
		in>>l[i];
		l[i]-='a';
	}
	if(n%2==1)
	{
	for(int i=0; i<(n+1)/2; i++)
	{
		a[l[i]][1]++;
		a[l[i]][0]+=i;
	}
	for(int i=(n+1)/2; i<n; i++)
	{
		a[l[i]][2]++;
		a[l[i]][0]+=n-i;
	}
	}
	else
	{		
		for(int i=0; i<n/2; i++)
	{
		a[l[i]][1]++;
		a[l[i]][0]+=i;
	}
	for(int i=n/2; i<n; i++)
	{
		a[l[i]][2]++;
		a[l[i]][0]+=(n+1)/2-(i-(n+1)/2);
	}
	}
	int N=1;
	__int64 maxS=count(l[0]);
	if(n%2==0)
	{
	for(int i=1; i<n; i++)
	{
	
		for(int j=0; j<30; j++)
		{
			a[j][0]+=a[j][2]-a[j][1];
		}
		a[l[(i+n/2-1)%n]][1]++;
		a[l[(i+n/2-1)%n]][2]--;
		a[l[(i+n/2-1)%n]][0]-=2;
		a[l[i-1]][1]--;
		a[l[i-1]][2]++;
		a[l[i-1]][0]+=2;

		__int64 aa=count(l[i]);
		if(maxS<aa)
		{
			maxS=aa;
			N=i+1;
		}
		
	}
	}
	else
	{
		for(int i=1; i<n; i++)
    {
        
        for(int j=0; j<60; j++)
        {
            a[j][0]+=a[j][2]-a[j][1];
        }
        a[l[(i+(n-1)/2)%n]][1]++;
        a[l[(i+(n-1)/2)%n]][2]--;
        a[l[(i+(n-1)/2)%n]][0]-=1;
        a[l[i-1]][1]--;
        a[l[i-1]][2]++;
        a[l[i-1]][0]+=2;

        __int64 aa=count(l[i]);
        if(maxS<aa)
        {
            maxS=aa;
            N=i+1;
        }
        
    }

	}
	out<<maxS<<"\n"<<N;    
} 