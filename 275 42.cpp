#include <fstream>
#include <iostream> 
using namespace std;

int main()
{
    char c=13,c2=10;
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    int n;
    in>>n;

    int pp[3];
    pp[0]=1;
    pp[1]=2;
    pp[2]=4;

    for(int i=0; i<n; i++)
    {
        char num[1000];
        in>>num;
        
        int k=0;
        while(num[k]!=0) k++;

        int ans=0;
        int p=0;

        for(int j=k-1; j>=0; j--)
        {
            ans+=pp[p]*(num[j]-'0');
            p++;
            p%=3;
        }
        if(ans%7==0) out<<"Yes";
        else out<<"No";
        out<<c<<c2;
    }
    
} 



