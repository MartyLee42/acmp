#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    bool tr=false;
    __int64 a[8];
    a[0]=6;
    a[1]=28;
    a[2]=496;
    a[3]=8128;
    a[4]=33550336;
    a[5]=8589869056;
    a[6]=137438691328;
    a[7]=2305843008139952128;
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    __int64 m,n;
    in>>m;
    in>>n;
    
    for(int i=0; i<8; i++)
    {
        if((a[i]>=m)&&(a[i]<=n)) 
        {
            tr=true;
            out<<a[i];
            out<<" ";
        }
    }
    if(!tr) out<<"Absent";
}

