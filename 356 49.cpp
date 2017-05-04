#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    __int64 n,f;
	double e,ff;
    __int64 p[10000],w[10000];
    __int64 a[100001][2];
    memset(a,0,100001*2*4);

    in>>e>>ff>>n;
    for(int i=0; i<n; i++)
    {
        in>>p[i]>>w[i];
		if(a[w[i]][1]!=0)
		{
			a[w[i]][1]=min(p[i],a[w[i]][1]);
		}
		else a[w[i]][1]=p[i];
		a[w[i]][0]=max(p[i],a[w[i]][0]);
    }

    ff-=e;
    if(ff<1)
    {
        out<<"This is impossible.";
        return 0;
    }
	f=int(ff);

    for(int i=0; i<=f; i++)
    {
        
        for(int j=0; j<n; j++)
        {
            if(w[j]<=i)
            {
                if(a[i-w[j]][0]!=0)
                    a[i][0]=max(a[i-w[j]][0]+p[j],a[i][0]);
                if(a[i][1]==0)
                {
                    if(a[i-w[j]][1]!=0)
                    a[i][1]=a[i-w[j]][1]+p[j];
                }
                else
                {
                    if(a[i-w[j]][1]!=0)
                    a[i][1]=min(a[i-w[j]][1]+p[j],a[i][1]);
                }
            }
        }
    }
    if(a[f][1]!=0 && a[f][0]!=0)
        out<<a[f][1]<<" "<<a[f][0];
    else
        out<<"This is impossible.";


}

 









