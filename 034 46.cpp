#include <fstream>

using namespace std;

int b[100010];

int main()
{
   
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n,k,ten=1,num=0;
    char a[100010];
    
    in>>n>>k>>a;

    
    for(int i=0; i<k && i<n; i++)
    {
        ten*=10;
        num=num*10+a[i]-'0';
        
    }
    b[num]=1;
    ten/=10;

    for(int i=k; i<n; i++)
    {
        num-=(a[i-k]-'0')*ten;
        num=num*10+a[i]-'0';
        b[num]++;
        
    }
    for(int i=0; i<100010; i++)
    {
        if(b[i]>1) 
        {
            out<<"YES";
            return 0;
        }
    }
    
    out<<"NO";
} 


