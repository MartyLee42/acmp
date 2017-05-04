#include <fstream>
#include <iostream> 
using namespace std;

__int64 func(__int64 x)
{
    if(x==0) return 0;
    if(x==1) return 1;
    if(x%2==0)
    {
        return(func(x/2));
    }
    else
    {
        return(func(x/2+1)+func(x/2));
    }
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    __int64 a;
    in>>a;
    out<<func(a);
}
 


