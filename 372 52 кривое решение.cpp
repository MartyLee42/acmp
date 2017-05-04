#include <iostream>
#include <stack>
using namespace std;

//кривое решение

#define Max 15

stack<int> a;
int b[Max];
int n;

void write()
{
	for(int i=0; i<n; i++)
	{
		if(b[i]==1) cout<<"(";
		if(b[i]==2) cout<<"[";
		if(b[i]==-1) cout<<")";
		if(b[i]==-2) cout<<"]";
	}
	cout<<"\n";
}

void pere(int k)
{
	if(a.size()==n-k)
	{
		stack<int> bb=a;
		for(int i=k; i<n; i++)
		{
			b[i]=-bb.top();
			bb.pop();
		}
		write();
		return; 
	}
	b[k]=1;
	a.push(1);
	pere(k+1);
	a.pop();

	b[k]=2;
	a.push(2);
	pere(k+1);
	a.pop();

	if(!a.empty())
	{
		b[k]=-a.top();
		a.pop();
		pere(k+1);
		a.push(-b[k]);
		
	}
}

int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);

	
	cin>>n;
	pere(0);
} 
