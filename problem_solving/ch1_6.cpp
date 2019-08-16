#include <iostream>
#include <vector>

bool is_abund(int a){
    
    int sum = 0;
    bool b = true;
    for (size_t i = 1; i < a; i++)
    {
        if (a % i == 0)
        {  
            if(a == i*i){
                sum += i;
            }
            sum += i;
        }
        
    }
    if (sum > a)
    {
        b = true;
    }
    else
    {
        b = false;
    }
    
    return b;
    
}
void get_abundents(int b){
    std::vector<int> vec;
    for (size_t i = 0; i < b; i++)
    {
        if (is_abund(i) == 1)
        {
            vec.push_back(i);
        }
        
    }
    for (auto const &s : vec)
    {
        std::cout << s << std::endl;
    }
    
    
}
int main(int argc, char const *argv[])
{
    int x;
    std::cout << "Entr the number" << std::endl;
    std::cin >> x;
    get_abundents(x);
    // std::cout << is_abund(x) << std::endl;;
    return 0;
}
