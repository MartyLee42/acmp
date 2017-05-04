#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int s,k;
    in>>s>>k;

    int s1=s;
    for(int i=0; i<k; i++)
    {
        if(s1>8)
        {
            out<<9;
        }
        else
        {
            out<<s1;
        }
        s1-=9;
        if(s1<0) s1=0;
    }

    s1=s;
    int l=1;


    out<<" ";
    if(s<=9*(k-1)) 
    {
        out<<1;
        s--;
    }
    else
    {
        out<<s-9*(k-1);
        s=9*(k-1);
        l=0;
    }
    for(int j=1; j<k-s/9-1; j++)
    {
        out<<0;
    }
    if(l==1) out<<(s)%9;

    for(int i=0; i<=s/9-1; i++)
        out<<9;
    
} 


