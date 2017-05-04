#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool palindrom(string s, int n)
{
    for(int i=0; i<n; i++)
    {
        if(s[i]!=s[n-i]) return(false);
    }
    return(true);
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    string st;    
    in>>st;
    bool t=false;
    for(int i=0; i<st.length()-1; i++)
    {
        if(st[i]!=st[i+1])
        {
            t=true;
            break;
        }
    }
    if(t)
    {
        int n=st.length();
        if(palindrom(st,n-1))
        {
            for(int i=0; i<n-1; i++)
            out<<st[i];
        }
        else
        {
            out<<st;
        }
        
    }
    else
    {
        out<<"NO SOLUTION";
    }

} 

