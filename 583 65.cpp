#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	freopen("INPUT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	
	int n;
	cin>>n;

	int ud=0,lr=0;
	int prUD=0,prLR=1;
	int firstturn=0;
	int direction=0;

	for(int i=0; i<n; i++)
	{
		char h;
		int a;
		cin>>h;
		if(h=='f')
		{
			cin>>a;
			if(direction==0 ||direction==2)
			{
				if(prUD!=direction)
				{
					prUD=direction;
					ud++;
				}
			}
			else
			{
				if(prLR!=direction && firstturn) lr++;

				prLR=direction;
				firstturn=1;
			}
		}
		else
		{
			if(h=='r') direction+=1;
			if(h=='l') direction+=3;
			direction%=4;
		}
		if(ud>=3 ||lr>=3)
		{
			cout<<"FALSE";
			return 0;
		}
	}
	cout<<"TRUE";
}
