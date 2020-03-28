#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    std::vector<int> a ={1,2,3};
    int fac = 4;
    for_each(begin(a),end(a),[&fac](int &val){
        val = val*fac;
        //fac = fac *2;
        fac--;
    });
    std::cout << fac <<"\n";
    for (auto item:a)
    {
        std::cout << item << " ";
    }
    std::cout<<"\n";
    
    return 0;
}
