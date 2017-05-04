#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

#define Max 100
int skobki[Max];

int count(int *a,int beg,int end)
{
	int ans=0;

	int now=-3;

	for(int i=beg; i<end; i++)
	{
		if(now<0)
		{
			if(a[i]>0)
			{
				if(now==-3)
					ans+=a[i];
				if(now==-4)
					ans-=a[i];
				if(now==-5)
					ans*=a[i];
			}
			else
			{
				if(i+1<skobki[i])
				{
					if(now==-3)
						ans+=count(a,i+1,skobki[i]);
					if(now==-4)
						ans-=count(a,i+1,skobki[i]);
					if(now==-5)
						ans*=count(a,i+1,skobki[i]);
				}
				i=skobki[i];
			}
		}

		if(now==0)
			now=a[i];
		else
			now=0;
	}
	return ans;
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	char in[Max];
	int ans;
	cin>>ans;

	cin.get(in,Max);

	int pos=0;
	while(in[pos]!='=') pos++;
	pos++;

	int a[Max];
	int pos2=0;
	int n=0;

	int b[Max];

	stack<int> s;
	bool tr=false;

	while(in[pos]>0)
	{

		while(in[pos]==' ') pos++;
		if(in[pos]<=0) break;
		if(in[pos]>='0' && in[pos]<='9') 
		{
			int aa=0;
			
			while(in[pos]>='0' && in[pos]<='9')
			{
				aa=aa*10+in[pos]-'0';
				pos++;
			}

			if(tr && (pos2>0 &&(a[pos2-1]>0 || a[pos2-1]==-1)))
			{
				a[pos2]=0;
				b[n]=pos2;
				pos2++;
				n++;
			}

			a[pos2]=aa;
			pos2++;
			tr=true;
			continue;
		}

		if(in[pos]=='(')
		{
			if(pos2>0 &&(a[pos2-1]>0 || a[pos2-1]==-1))
			{
				a[pos2]=0;
				b[n]=pos2;
				n++;
				pos2++;
			}
			s.push(pos2);
		}
		if(in[pos]==')')
		{
			skobki[s.top()]=pos2;
			s.pop();
		}

		a[pos2]=in[pos]-'('-2;

		pos2++;
		pos++;
	}
	int nn=1;
	for(int i=0; i<n; i++)
		nn*=3;

	for(int i=0; i<nn; i++)
	{
		int ii=i;
		for(int l=0; l<n; l++)
		{
			a[b[l]]=ii%3-5;
			ii/=3;
		}

		int ans2=count(a,0,pos2);

		if(ans2==ans)
		{
			cout<<ans<<'=';
			for(int j=0; j<pos2; j++)
			{
				if(a[j]>0) cout<<a[j];
				else
				{
					if(a[j]==-2) cout<<"(";
					if(a[j]==-1) cout<<")";
					if(a[j]==-3) cout<<"+";
					if(a[j]==-4) cout<<"-";
					if(a[j]==-5) cout<<"*";
				}
			}
			
			return 0;
		}
		
	}
	cout<<-1;

} 
