#include <string>
#include <iostream> 

using std::cin;
using std::cout;
using std::endl;
using std::string;


template <class T>

constexpr T getMax(T a,T b){
    return (a>b)?a:b;
}

constexpr int feb(int val){
    if (val == 0)
    {
        return 0;
    }
    else if (val == 1)
    {
        return 1;
    }

    else
    {
        return feb(val - 1) + feb(val - 2);
    }
    
    
    
}

int main(int argc, char const *argv[])
{
   

    static_assert(feb(10)==55,"Unexpected Fibonacci number.");
    return 0;
}
