#include <iostream>
#include <vector>

using std::cout;
using vect = std::vector<int>;

bool is_palendrom(unsigned n){
    vect buff;
    int val;
    bool check = true;
    
    while(n%10 != 0 || n/10 != 0){
        
       
        val = n%10;
        n = n/10;
        buff.push_back(val);
       
       
        
        
        
    }
    for(int i=0;i < buff.size();i++){
        cout << buff[i] << " ";
    }
    cout << std::endl;
    
    int i = buff.size() -1;
    int j = 0;
   
   
    while (i >= j)
    {   
        
        if(buff[i] == buff[j]){
            check = true;
            j += 1;
            i -= 1;
            
        }
        else
        {
            check = false;
            break;
        }
        
        
    }

    
 return check;   
}

int main(int argc, char const *argv[])
{
    
    bool chekPal = is_palendrom(11);
    cout << chekPal << std::endl;
    return 0;
}
