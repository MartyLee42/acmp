#include <fstream>
#include <iostream>
using namespace std;

double a[100][100];

double Max=1E50;

void floyd(double l[100][100],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
				if((l[j][i]>-Max || l[i][k]<Max) && (l[i][k]<Max || l[j][i]>-Max))
                l[j][k]=min(l[j][k],l[j][i]+l[i][k]);
				
				if(l[j][k]>Max)l[j][k]=Max*Max;
            }
        }
    }
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    double l[100][100];

    int n;
    in>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            in>>l[i][j];
			
                if(l[i][j]==0) l[i][j]=Max*Max;
				
           
        }
    }
   
   
    floyd(l,n);
    memcpy(a,l,100*100*sizeof(double));
    floyd(l,n);
	
	
	

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
			    if(a[i][j]>l[i][j])
				{
					l[i][j]=-Max;
				}
        }
    }
	floyd(l,n);
	
	for(int i=0; i<n; i++)
	{
        for(int j=0; j<n; j++)
		{
			if(i==j)
			{
				if(l[i][j]<-Max)
				out<<2;
				else out<<1;
			}
			else
			{
				if(l[i][j]<Max && l[i][j]>-Max) out<<1;
				else
				{
					if(l[i][j]<-Max) out<<2;
					else out<<0;
				}
			}
			out<<" ";
		}
		out<<"\n";
	}
} 





