#include <fstream>
using namespace std;
#define Max 1000 

void delete11(int *a);
void deleteEnd20(int *a);
void deleteEnd02(int *a);

void delete2(int *a)
{
	int t=0;
	for(int i=Max-3; i>1; i--)
	{
		if(a[i]>1)
		{
			t=1;
			a[i]-=2;
			a[i+2]++;
			a[i-1]++;
		}
	}
	if(t)
	{
		delete2(a);
		delete11(a);
		deleteEnd20(a);
		deleteEnd02(a);
	}

}

void delete11(int *a)
{
	int t=0;
	for(int i=Max-1; i>1; i--)
	{
		if(a[i]>0 && a[i-1]>0)
		{
			t=1;
			a[i-2]++;
			a[i]--;
			a[i-1]--;
		}
	}
	if(t)
	{
		delete2(a);
		delete11(a);
		deleteEnd20(a);
		deleteEnd02(a);
	}
}
void deleteEnd02(int *a)
{
	if(a[Max-1]>=2)
	{
		a[Max-2]++;
		a[Max-1]-=2;
		delete2(a);
		delete11(a);
		deleteEnd20(a);
		deleteEnd02(a);
	}
}
void deleteEnd20(int *a)
{
	if(a[Max-2]>=2)
	{
		a[Max-3]++;
		a[Max-2]-=2;
		a[Max-1]++;
		delete2(a);
		delete11(a);
		deleteEnd20(a);
		deleteEnd02(a);
	}
}


int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");
	
	int a[Max];
	char aa[Max];
	memset(a,0,Max*4);

	in>>aa;
	int l=0; 
	while(aa[l]>0)l++;
	for(int i=0; i<l; i++)
		a[Max-i-1]=aa[l-i-1]-'0';

	l=0;
	in>>aa;
	while(aa[l]>0)l++;
	for(int i=0; i<l; i++)
		a[Max-i-1]+=aa[l-i-1]-'0';

	delete2(a);
	delete11(a);
	deleteEnd20(a);
	deleteEnd02(a);

	l=0;
	while(a[l]==0 && l<Max) l++;
	if(l==Max) out<<0;
	for(int i=l; i<Max; i++)
	{
		out<<a[i];
	}

	

}












