#include <iostream>
#include <vector>

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
void sexy_primes(int e){

std::vector<int> vec;

for (size_t i = 1; i <= e; i++)
{
    if (is_prime(i) && is_prime(i+6))
    {
        std::cout << i << " " << i+6 << std::endl;
    }
    
}

// std::vector<int> vec2;

// // std::vector<int>::iterator it = vec.begin();

// for (size_t i = 1; i <= e; i++)
// {
//     if(is_prime(i)==1){
//         vec.push_back(i);
//     }
// }
// for (std::vector<int>::iterator it = vec.end() ; it != vec.begin();it--)
// {
//     for (size_t j = 0; j < *it; j++)
//     {
//         if (*it - vec[j] == 6)
//         {
//             vec2.push_back(vec[j]);
//             vec2.push_back(*it);
//         }
        
//     }
    
// }
// for (auto &s : vec2)
// {
//     std::cout << s << std::endl;
// }




}

int main(int argc, char const *argv[])
{
    sexy_primes(31);
    return 0;
}
