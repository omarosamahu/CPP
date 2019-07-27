#include <iostream>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <vector>

class SquareRoot
{
    
public:
   // Add callback here
   using TCallback = std::function<void(const size_t,const double)>;
   using TCallbackVector = std::vector<TCallback>;
   
   void add_callbacks(TCallback _callback){
       m_callbacks.push_back(_callback);
   }

   // Define the run function
   double run(const double input){
       if(input == 0) throw 0;
       this->itr = 0;
       double guess = input;

       while (std::fabs(guess - input/guess) > this->epsilon) {
           for (auto &cb : m_callbacks)
           {
               cb(itr,guess);
           }
           
       guess = (guess + input / guess) / 2.0;
       ++itr;
    }
    return guess;
    }
private:
    size_t itr;
    double epsilon = 1e-6;
    TCallbackVector m_callbacks;

};






int main(int argc, char const *argv[])
{
   SquareRoot obj;
   auto cb_l = [](const size_t iteration,const double g){std::cout << iteration <<" : " << g <<"(Lambda)\n";};
   obj.add_callbacks(cb_l);
   std::cout << obj.run(1234.5*1234.5) <<std::endl;
}
