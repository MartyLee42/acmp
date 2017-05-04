#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

bool l(pair <int, int >a, pair <int, int> b )
{
    if(a.second<b.second) return true;
    return false;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    pair <int,int> c[20000];
    int n;
    in>>n;
    for(int i=0; i<n; i++)
    {
        c[i].first=i+1;
        in>>c[i].second;
    }
    sort(c,c+n,l);
    for(int i=0; i<n; i++)
    {
        out<<c[i].first<<" ";
    }
}

