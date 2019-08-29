#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Emplyee
{
private:
    string firstname;
    string secondname;
    int salary;
public:
     Emplyee(string first,string seconed,int sal):firstname(first),secondname(seconed),salary(sal){};
    ~Emplyee(){
        
    }

    string getName(){
        return secondname +", "+ firstname; 
    }
    int getSalary(){
        return salary;
    }
};

int main(int argc, char const *argv[])
{
    vector<Emplyee> staff{
        {"Omar","Osama",3000},
        {"Hany","Hesham",2000},
        {"Ahmed","Shaban",1000},
        {"Fake","Name",2000},
        {"Osama","Tarek",2000}
    };
     
    //sort(staff.begin(),staff.end(),[](Emplyee e1,Emplyee e2){return e1.getSalary() > e2.getSalary();});
    auto sorted = is_sorted(staff.begin(),staff.end(),[](Emplyee e1,Emplyee e2){return e1.getSalary() > e2.getSalary();});
    vector<Emplyee>::iterator it = staff.begin();
   // cout << *it <<endl;

   // auto h = *(max_element(begin(staff),end(staff)));

    return 0;
}
