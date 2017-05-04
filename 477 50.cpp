#include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    char t[500];
    in>>t;
    int s=0,i=0;
    while(t[i]<='9' && t[i]>='0')
    {
        s+=t[i]-'0';
        i++;
    }
    if(s%3==0) out<<2;
    else out<<1<<" "<<s%3;
}

