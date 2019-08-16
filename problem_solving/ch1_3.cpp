#include <iostream>

int  gcd(uint16_t a,uint16_t b){
    uint16_t cnt = 1;
    uint16_t var = 0;
   
    while (b / cnt != 0 && a / cnt != 0)
    {  
      
      if(a % cnt == 0 && b % cnt ==0)
      {
          var = cnt;
          
      }
      cnt += 1;
      
    }
    return var;
}

int lcm(int a,int b){
    
    return (a*b) / gcd(a,b);
}

int main(int argc, char const *argv[])
{
    std::cout << lcm(12,18) << std::endl;
    return 0;
}
