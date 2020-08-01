// 
#include <cstring>
#include <cstdlib>
#include <iostream>
// STL
#include <vector>
#include <algorithm>

void printVector(const std::vector<uint32_t>& vec){
    for(const auto& item:vec){
        std::cout << item << "\n";
    }
}
int main(int argc, char const *argv[])
{
    uint32_t* p1 = new uint32_t[10];
    uint32_t* p2 = new uint32_t[5];
    uint8_t BUFFER_SIZE = 5;

    *(p1 + 0) = 10;
    *(p1 + 1) = 20;
    *(p1 + 2) = 30;
    *(p1 + 3) = 40;
    *(p1 + 4) = 50;
    *(p1 + 5) = 60;
    *(p1 + 6) = 70;
    *(p1 + 7) = 80;
    *(p1 + 8) = 90;
    *(p1 + 9) = 100;


    *(p2 + 0) = 1;
    *(p2 + 1) = 2;
    *(p2 + 2) = 3;
    *(p2 + 3) = 4;
    *(p2 + 4) = 5;
   


    std::vector<uint32_t> mData(BUFFER_SIZE * 3);
    
    // First method
    mData.resize(BUFFER_SIZE * 3);
    memcpy(mData.data(),p1 + 0,BUFFER_SIZE * sizeof(uint32_t));
    memcpy(mData.data() + BUFFER_SIZE , p2, BUFFER_SIZE* sizeof(uint32_t));
    memcpy(mData.data() + (2*BUFFER_SIZE) ,p1 + BUFFER_SIZE,BUFFER_SIZE* sizeof(uint32_t));
    
    // Second method
    std::copy_n(p1,BUFFER_SIZE * sizeof(uint32_t),mData.begin());
    std::copy_n(p2,BUFFER_SIZE * sizeof(uint32_t),mData.begin() + BUFFER_SIZE);
    std::copy_n(p1 + BUFFER_SIZE,BUFFER_SIZE * sizeof(uint32_t),mData.begin() + 2*BUFFER_SIZE);
    // Third method
    std::vector<uint32_t> vecData(mData.data(),mData.data() + mData.size());
    std::cout << mData.size() << "\n";
    printVector(mData);
    return 0;
}
