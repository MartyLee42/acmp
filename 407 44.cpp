#include <fstream>

using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUt.txt");

    int n, k;
    int a[20];
    int l[1060010];
    for(int i=0; i<1060010; i++)
    {
        l[i]=20003001;
    }
    in>>n;

    for( int i=0; i<n; i++)
    {
        in>>a[i];
        l[a[i]+3000]=1;
    }

    in>>k;
    k+=3001;

    for(int i=3001; i<=k; i++)
    {    
        for(int j=0; j<n; j++)
        {
            l[i]=min(l[i],l[i-a[j]]+1);
        }
    }    

    if(l[k-1]>1000000)
        out<<-1;
    else
        out<<l[k-1];
} 



