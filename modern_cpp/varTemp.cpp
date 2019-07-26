#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <tuple> 

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::tuple;
using std::get;
using namespace std::chrono;



class varTemp
{
private:
    /* data */
public:
    varTemp()
        {
            cout << "The class constructor" <<endl;
        }

    ~varTemp()
        {
            cout << "The class destructor" <<endl;
        }
    void sayHello(){
        cout << "Hello ya negm" << endl;
    }
};

void countTime(milliseconds ms){
    cout << ms.count() << endl;
}

int main(int argc, char const *argv[])
{
    tuple<int,string,float> t(25,"Omar",10);

    auto tup = std::make_tuple(9,"3amooooor","10s");
    cout << get<0>(t) << endl << get<1>(t) << endl << get<2>(t) << endl;
    cout << get<0>(tup) << endl << get<1>(tup) << endl << get<2>(tup) << endl;
    // auto ptr = std::make_unique<varTemp>();
    // auto x = 2s;
    // auto y = 250ms;
    // cout << "x = 2s:";
    // auto z  = x + y;
    // countTime(z);
   
    // ptr->sayHello();
    
    // varTemp * v = new varTemp();
    // v->sayHello();
    // delete(v);
     return 0;
}



// template <typename T>
// T pi = 3.141592;

// [[deprecated]]
// void rubbish(){
//     cout << "This is a fuckin rubbish" <<endl;
// }
