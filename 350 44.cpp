#include <fstream>
using namespace std;


int n;
int p=49000;
ofstream out("OUTPUT.txt");

char a[9];
char b[8][50000];
char c=10,c1=13;

void reverse(int m)
{
    int j=0;
    while(j<m-1)
    {
        swap(a[j],a[m-1]);
        j++;
        m--;
    }
}

void write()
{
    for(int i=n; i>=1; i--)
        b[n-i][p]=a[i-1];    
    p--;
}

void lex(int m)
{
    if(m==1) write();
    else
    {
        for(int i=0; i<m; i++)
        {
            lex(m-1);
            if(i<m-1)
            {
                swap(a[i],a[m-1]);
                reverse(m-1);
            }
        }
    }
}



int main()
{
    ifstream in("INPUT.txt");
    
    
    in>>a;
    while(a[n]!=0) n++;

    for(int l=0; l<n; l++)
    {
        for(int h=l+1; h<n; h++)
        {
            if(a[l]>a[h]) swap(a[l],a[h]);
        }
    }

    lex(n);

    int i=49000;

    while(b[0][i]!=0)
    {
        i--;
    }
    i++;
    for(int k=i; k<=49000; k++)
    {
        for(int j=0; j<n; j++)
            out<<b[j][k];
        i--;
        out<<c1<<c;
    }

} 

