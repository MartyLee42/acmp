#include <fstream>
using namespace std;
int main()
{
    ifstream i("INPUT.txt");
    ofstream o("OUTPUT.txt");
    __int64 n,k;
    i>>n>>k;
    o<<(n+1)*(k+1)*n*k/4;
} 



