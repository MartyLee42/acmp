#include <iostream>
using namespace std;


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	
	__int64 n,k,ans;

	cin>>n>>k;

	ans=1;
	for(int i=0; i<n; i++)
		ans*=n;

	ans-=(n-1)*k;

	cout<<ans;
	
 }
