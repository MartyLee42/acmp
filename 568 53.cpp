#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

struct way {

	int a;
	int b;
	int c;

};

stack<int> st;

int ans[200001];
int bb[10001];
way a[200000];


int pos=0;
void Cycle(int i)
{
	int j=bb[i];
	while(a[j].a==i)
	{
		if(a[j].c==0)
		{
			a[j].c=1;
			Cycle(a[j].b);
		}
		j++;
	}

	ans[pos]=i;
	pos++;
}

int compare(way a, way b)
{
	if(a.a<b.a) return 1;
	return 0;
}



int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	int n, m;
	in>>n>>m;

	
	for(int i=0; i<m; i++)
	{
		in>>a[2*i].a>>a[2*i].b;
		a[2*i+1].a=a[2*i].b;
		a[2*i+1].b=a[2*i].a;
		a[2*i].c=0;
		a[2*i+1].c=0;
	}
	sort(a,a+2*m, compare);

	int kk=1;
	for(int i=0; i<2*m; i++)
	{
		bb[kk]=i;
		while(a[i].a==a[i+1].a) i++;
		kk++;
	}

	Cycle(1);

	out<<2*m<<'\n';

	for(int i=0; i<2*m+1; i++)
	{
		out<<ans[i]<<" ";
	}
	
}