#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

bool l(pair <int ,int > a, pair <int ,int > b)
{
    if(a.second<b.second) return true;
    return false;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n;
    pair <int, int > a[100000];
    in>>n;
    for(int i=0; i<n ;i++)
    {
        a[i].first=i+1;
        in>>a[i].second;
    }
    sort(a,a+n,l);
    int c=a[1].first,b=a[0].first,min=a[1].second-a[0].second;

    for(int i=1; i<n ;i++)
    {
        if(a[i].second-a[i-1].second<min)
        {
            c=a[i].first;
            b=a[i-1].first;
            min=a[i].second-a[i-1].second;
        }
    }
    out<<min<<" "<<b<<" "<<c;
}



