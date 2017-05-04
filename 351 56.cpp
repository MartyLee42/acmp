#include <fstream>
using namespace std;


int main()
{
    ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");
	int n,k;
	char h[100100];
	int h1[100100];
	in>>n>>k>>h;

	h1[0]=0;
	for(int i=1; i<n; i++)
	{
		h1[i]=h1[i-1];
		if(h[i]!=h[i-1]) h1[i]++;
		for(int j=i-1; j>=i-k && j>=0 ; j--)
		{
			if(h[i]!=h[j]) h1[i]=min(h1[i],h1[j]+1);
			else 
			{
				h1[i]=min(h1[j],h1[i]);
				break;
			}
		}
	}
	out<<h1[n-1];
} 
