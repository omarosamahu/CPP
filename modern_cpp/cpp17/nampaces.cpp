#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <type_traits>
#include <map>

using std::find;
using std::vector;
using std::string;
using std::cout,std::cin,std::endl;
using std::is_integral;

template <class T>
auto length(T const& value){
    if constexpr(is_integral<T>::value){
        return value;
    }
    else
    {
        return value.length();
    }
    
}

void print(const string& msg,const vector<string>&v){
    cout << ' '<< msg << ": "<< endl;
    for (auto const& s:v)
    {
        cout << s << endl;
    }   
}
std::map<string,string> italianDic{
    {"beat","home"},{"kora","ball"}
};

int main(int argc, char const *argv[])
{
    auto [pos,suc] = italianDic.insert({"bab","door"});
    if (suc)
    {
        cout <<"ok" <<"\n";
    }
    for (auto const& [arab,eng]:italianDic)
    {
        cout <<" " << arab <<" " <<eng <<" " <<"\n";
    }
    
    // int n{15};
    // string s{"I am Omar"};
    // cout << length(n) << endl;
    // cout << length(s) << endl;
    return 0;
} 
    //vector<string> names{"omar","osama","hussein","mohammed"};
    // print("Before",names);
    // if (auto const it = find(begin(names),end(names),"omar");it != end(names))
    // {
    //     *it = "***"; 
    // }
    // print("After",names);
    
    // if (auto const it = find(begin(names),end(names),"***");it != end(names))
    // {
    //     *it = "*"; 
    // }
    // print("After",names);
    