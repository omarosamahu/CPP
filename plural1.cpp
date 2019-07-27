#include <iostream>
#include <string>

using std::cout;
using std::endl;

void pass(double  y){
    y += 3;
    double x = y + 2 ;
    cout << x << endl; 
}

double passByAddr(double &y){
   
    return y*2;
}


int main(int argc, char const *argv[])
{
    const int a = 10;
    int b = 5;
    const int * p = &a;
    cout << p << endl;
    ++p;
    cout << p << endl;
    int * const p2 = &b;
    *p2 = 30;
    cout << *p2 << endl;

    // double val = passByAddr(pi);
    // cout << val << endl; 
    // cout << pi << endl;
    // int i = static_cast<int>(d);
    
    return 0; 
}
