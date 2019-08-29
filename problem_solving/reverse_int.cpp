#include <iostream>
#include <math.h>

int main(int argc, char const *argv[])
{
    int x =198;
    int y = x;
    int rem = 0;
    int div = 0;
    int val = 0;
    int cnt = 1; 
    while (y / 10 != 0)
    {
        y = y / 10;
        cnt += 1;
    }
    
    while(x%10 != 0 || x/10 != 0){
        rem = x %10;
        x = x /10;
        val += rem * pow(10,(cnt));
        cnt = cnt - 1; 
    }
    std::cout << val/10 <<"\n";
    return 0;
}
