#include <iostream>
#include <math.h>
#include <vector>
#include <functional>


class MemberFunctionCall{
public:
    void Call(const size_t itr,const double guess){
        std::cout << itr << " : " << guess << "\n";
    }
};
class SquareRoot{
public:
    using TCallback  = std::function<void(const size_t,const double)>;
    using TCallbacks = std::vector<TCallback>;

    void add_callbacks(TCallback cb){
                callbackVec.push_back(cb);
        }
    double run(const double input){
            double guess = input;
            while(std::fabs(guess - input/guess) > this->epsilon){
                for(const auto &cb: callbackVec){
                  cb(itr,guess);   
                }
                guess = (guess + input / guess) / 2.0;
                ++itr;
            }
        return guess;
        }
private:
    const double epsilon = 1e-6; // Maximum Allowed Error.
    size_t itr = 0;
    
    TCallbacks callbackVec;
};

int main(int argc, char const *argv[])
{
    SquareRoot s;
    

    MemberFunctionCall cb_tmp;

    auto cb_fun = std::bind(&MemberFunctionCall::Call,&cb_tmp,std::placeholders::_1,std::placeholders::_2);
    s.add_callbacks(cb_fun);
    std::cout << " Result: " <<  s.run(1234.5*1234.5) << std::endl;
    return 0;
}
