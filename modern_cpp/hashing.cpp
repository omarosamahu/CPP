#include <iostream>
#include <unordered_map>


int main(int argc, char const *argv[])
{
    std::unordered_map<std::string,float> unmap;
    unmap["PI"] = 3.14;
    unmap["root1"] = 1.44;
    unmap["root2"] = 1.732;
    unmap["log10"] = 2.302;

    // Insert value inside map
    unmap.insert(std::make_pair("e",2.718));
    
    std::string k = "PI";
    // if (unmap.find(k) == unmap.end())
    // {
    //     std::cout << k << "Found\n";
    // }
    // else
    // {
    //     std::cout << "Found " << k << std::endl;
    // }
    std::unordered_map<std::string,float>::iterator itr;
    for (itr = unmap.begin();itr != unmap.end();itr++)
    {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
    
    
    
    
    return 0;
}
