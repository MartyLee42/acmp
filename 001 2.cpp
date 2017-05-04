 #include <fstream>
using namespace std;

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    int c,b;
    in>>c>>b;
    out<<c+b;
    __int64 a; 
    for(__int64 i=0; i<545000000; i++) a++;    
}
 
 