#include <iostream>
#include <fstream>
#include <string> 
#include <memory>
#include <algorithm>
#include <vector> 

using std::sort;
using std::endl;
using std::make_unique;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;


int main(int argc, char const *argv[])
{   
    auto ptr = make_unique<int>(90);
    auto x = 80;
    // cout << &ptr << endl;
    auto lambda = [x = x](){
        cout << "The value inside lambda is " << (x+4) <<endl;
    };
    lambda();
    cout << x << endl;
    return 0;
}

//open file for reading 
    // ifstream file{"data.txt"};
    // //Start read lines 
    // vector<string> lines;
    // string line;
    // while (getline(file,line))
    // {
    //     lines.push_back(line);
    // }
    
    // //Sort 
    // sort(begin(lines),end(lines),
    // [](auto const& a,auto const& b){
    //     return a.length() < b.length();
    // });
    // //Print data 
    // for (auto const& s:lines)
    // {
    //     cout << s <<endl;
    // }
    
