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

unsigned gcd2(unsigned int a,unsigned int b){
    while (b != 0)
    {
        unsigned int r = a % b;
        a = b ;
        b = r;
    }
    return a;
}

int main(int argc, char const *argv[])
{
     int arr = gcd(36,24);     
     
}
