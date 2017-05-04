#include <fstream>
using namespace std;

int otr(int a1,int a2, int b1, int b2)
{
    if((b1<=a2 && b1>=a1) || (b2<=a2 && b2>=a1)) return 1;
    return 0;
}


int pere(int x1,int x2,int y1, int y2, int a1,int a2,int b1, int b2)
{
    if(otr(x1,x2,a1,a2)==1 && otr(y1,y2,b1,b2)==1) return 1;
    return 0;
    
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n,r,x[200][2],y[200][2],a[200];
    memset(a,0,800);

    in>>n;

    for(int i=0; i<n; i++)
    {
        in>>x[i][0]>>y[i][0]>>x[i][1]>>y[i][1];
        if(x[i][0]>x[i][1]) swap(x[i][0],x[i][1]);
        if(y[i][0]>y[i][1]) swap(y[i][0],y[i][1]);
        in>>r;
        x[i][0]-=r;
        x[i][1]+=r;
        y[i][0]-=r;
        y[i][1]+=r;
    }
	int count =1;
	int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(pere(x[i][0],x[i][1],y[i][0],y[i][1],x[j][0],x[j][1],y[j][0],y[j][1])==1)
            {
                 if(a[i]==0)
                      a[i]=a[j];
				 
				 if(a[j]==0)
                      a[j]=a[i];

				 if(a[j]==0 && a[i]==0)
				 {
                      a[j]=a[i]=count;
					  count++;
					  ans++;
				 }
				 if(a[j]!=0 && a[i]!=0 && a[j]!=a[i])
				 {
					 ans--;
					 int p=a[j];
                      for(int l=0; l<200; l++)
					  {
                           if(a[l]==p) a[l]=a[i];
					  }
				 }
	       			 
            }
        }
    }
   out<<ans;
    
    
 } 


