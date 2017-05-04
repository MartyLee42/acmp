#include <string>
#include <fstream>
using namespace std;

__int64 a[101][23010];
__int64 aa[23010];

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int N,l,L,r,R;

    in>>N>>l>>L>>r>>R;
    

    memset(a,0,101*23010);
    
    for(int i=0; i<L; i++)
        in>>a[0][i];


    for(int i=r; i<l+r; i++)
        a[1][r+l-1]+=a[0][i];

    for(int i=l+r; i<l+R; i++)
        a[1][i]=a[1][i-1]+a[0][i]-a[0][i-l];

    
    memset(aa,0,23010);

    for(int i=r; i<l+R; i++)
        aa[i]=a[1][i];
    
    for(int i=l+R; i<L; i++)
        aa[i]=aa[i-1]+a[0][i]-a[0][i-l];

    __int64 minN,minO;
    __int64 maxx;
    maxx=18000000000000000;
    for(int j=2; j<=N; j++)
    {
        minN=(r+l)*(j-1)-1;
		minO=maxx;
        for(int i=(r+l)*j-1; i<min(L,(R+l)*j); i++)
        {
            
            a[j][i]=aa[i];
            if(minN<i-l-R)
            {
                minN=i-l-R;
                minO=a[j-1][minN];
            }
			if(minO>=a[j-1][i-r-l] && a[j-1][i-r-l]!=0)
			{
				minO=a[j-1][i-r-l];
				minN=i-r-l;
			}
			else
			{
                for(int k=minN; k<=i-r-l;k++)
                {
                    if(minO>a[j-1][k] && a[j-1][k]!=0)
                    {
                        minO=a[j-1][k];
                        minN=k;
                    }
                }
			}
            a[j][i]+=minO;
        }
    }
    __int64 ans=maxx;
    for(int i=L-R-1; i<L-r; i++)
    {
        if(ans>a[N][i]&& a[N][i]!=0)
        {
            ans=a[N][i];
        }
    }
    if(ans==maxx) 
    {
        out<<"No solution.";
        return 0;
    }
    out<<ans;
    
} 