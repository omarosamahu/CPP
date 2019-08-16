#include <iostream>

void nat_div(int *arr,int s){
    for(int i=0;i<s;i++){
        if(arr[i]%3 ==0 || arr[i]%5 ==0){
            std::cout << "The element " << arr[i] << " is divisible by 3 or 5 \n"; 
        }
    }
}

int main(int argc, char const *argv[])
{    
    int n;
    std::cout << "Please enter the range of elemnts \n";
    std::cin >> n;
    int x[n];
    for(int i =0;i<n;i++){
        std::cin >> x[i];
    }
    nat_div(x,n);
    return 0;
}
