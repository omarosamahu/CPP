#include "Tweeter.h"
#include "status.h"
#include <iostream>


using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{       int y = 0;
        Person * p = new Person("omar","osama");
         
       
        // p.setValue(10);
        // y = p.getVal();
        // y += 10;
        // cout << y << endl;

    // Person p = Person("omar","osama");
    Tweeter t = Tweeter("lionel","messi");
    cout << t.getName() << endl;
    // cout << t.getName2() << endl;
    // Status s = pending;
    // s = approved;
    // FileErr fe = FileErr::notFound;
    // fe = FileErr::ok;

    // cout << p.getName() << endl;
    
    return 0;
}
