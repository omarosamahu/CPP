#include <string>

class Person{
    private:
    std::string firstname;
    std::string seconedname;
    int x;

        
    public:
    Person(std::string first,std::string seconed):firstname(first),seconedname(seconed){};
    // Person()= default;

    void setValue(int y){
        x = y;
    }

    int getVal() {
        return x;
    }
    std::string getName() const{
        return  firstname + " " + seconedname;
    }
};