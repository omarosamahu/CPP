#include <string>
#include "Person.h"

class Tweeter : public Person
{
private:
    std::string name;
    std::string name2;
    int val;
public:
    Tweeter(std::string n1,std::string n2):Person(n2,n1){
        
    }
    
   
    
    // ~Tweeter : Person();
};


