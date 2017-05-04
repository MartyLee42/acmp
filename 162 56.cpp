#include <fstream>

int main()
{
    int n,m,a;
    std::ifstream i("INPUT.txt");
    std::ofstream o("OUTPUT.txt");
    i>>n>>m;
    a=2*(m*n+n+m);
    m%2==1&&n%2==1||n==1||m==1? a-=2:a;
    o<<a;
} 

