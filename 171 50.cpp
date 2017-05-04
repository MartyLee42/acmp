#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    __int64 n, ans=1;
    
    in>>n;

    for(int i = 2; i < 1000; i++)
    {
        int k=0;
        while(n % i == 0)
        {
            k++;
            n=n/i;
        }
        ans*=(k+1);
    }
    out<<ans;
    
} 

