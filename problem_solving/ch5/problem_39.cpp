#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

constexpr int func(int a,int b){
    return a + b;
} 

int main(int argc, char const *argv[])
{
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::chrono::time_point<std::chrono::high_resolution_clock> end;
  start = std::chrono::system_clock::now();
  std::function<int(int,int)> funPtr{func};
  std::cout << funPtr(3,5) <<std::endl;
  end = std::chrono::system_clock::now();
    
  
  double t_val = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
  std::cout << "Time elapsed during the execution of the function is: " << t_val << " sec \n";
  return 0;
}
