#include <iostream>


bool is_prime(int a){
    int c = 2;
    bool b;
    
    if (a == 1 || a == 2)
    {
        b = true;
        return b;
    } 
    else
    {
       for (size_t i = 2; i < a; i++)
       {
           if (a % i == 0)
           {
               b = false;
               break;
           }
           else
           {
               b = true;
           }
           
           
       }
       
        
    }
    
   return b; 
     
}
int get_largest_prime(int n){
    int val;
    for (size_t i = n - 1; i > 0; i--)
    {
        if (is_prime(i) == 1)
        {
            val = i;
            break;
        }
        
    }
    return val;
}
int main(int argc, char const *argv[])
{  
    int x;
    std::cout << "Entr the number" << std::endl;
    std::cin >> x;
    std::cout << get_largest_prime(x) << std::endl;
   
    return 0;
}
