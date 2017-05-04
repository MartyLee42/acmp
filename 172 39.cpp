#include <iostream>
#include <fstream>

using namespace std;

int a1[100];




int main()
{
    
    for(int i=0; i<100; i++)
    {
        a1[i]=0;
    }
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    __int64 div;
    char ch[100];

    in>>ch;
    in>>div;
    int j=0;

    while(ch[j]!=0)
    {
        j++;
    }
    for(int k=j-1; k>=0;k--)
    {
        a1[k]=ch[k]-'0';
    }
    __int64 n=0,m=0;
    for (int i=0; i<j; i++)
    {
        n = n*10+a1[i];
        if (n < div && m==0 && i > 0) continue;
        m=1;
        n = n % div;
    }

    out<<n;

} 


