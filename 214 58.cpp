#include <iostream>
#include <fstream>
using namespace std;


int main()
{
     ifstream in("INPUT.txt");
     ofstream out("OUTPUT.txt");
     int a,b;
     in>>a>>b;
     if((a%2+b%2)==0)out<<2;
     else out<<1;
}

