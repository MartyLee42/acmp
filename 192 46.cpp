#include <fstream>
using namespace std;

int a[10001];
void next(int n)
{
    int i=n-1;
    while(a[i]<a[i-1]) i--;

    if(i<=0) return;
    
    int m=100000,k=i;

    for(int j=i+1; j<n; j++)
        if(a[j]<m && a[j]>a[i-1]) 
        {
            m=a[j];
            k=j;
        }

    swap(a[i-1],a[k]);
    int l=n-1;
    while(i<l)

    {
        swap(a[i],a[l]);
        i++;
        l--;
    }
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n;
    in>>n;

    for(int i=0; i<n ;i++)
        in>>a[i];

    next(n);

    for(int j=0; j<n ;j++)
        out<<a[j]<<" ";
} 


