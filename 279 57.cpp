#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;



int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);

	string a;
	cin>>a;

	stack<char> b;


	int ans=0;
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]=='(' || a[i]=='[')
		{
			b.push(a[i]);
		}
		else
		{
			if(b.empty()) 
			{
				ans=-1;
				break;
			}
			else
			{
				if((b.top()=='(' && a[i]==']')|| (b.top() == '[' && a[i]==')'))
					ans++;
				b.pop();
				
			}
		}
	}

	cout<<ans;
} 
