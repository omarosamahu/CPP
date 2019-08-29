#include <iostream>
#include <vector>

using vect = std::vector<int>;

vect getSumforTwoVectors(vect a,vect b){
    vect c;
    for (size_t i = 0; i < a.size(); i++)
    {
        if(a[i] + b[i] > 10){
            c.push_back((a[i] + b[i]) / 10);
            a[i+1] = a[i+1] + ((a[i] + b[i]) % 10);
            }
        else
        {   
            c.push_back(a[i]+b[i]);
        }
    }
    return c;
}
int main(int argc, char const *argv[])
{
    vect x = {3,32,1};
    vect y = {2,34,3};
    vect z = getSumforTwoVectors(x,y);
    
    for(size_t j = 0; j< z.size();j++){
        std::cout << z[j]<< "\n";;
    }
    
    return 0;
}
