#include <iostream>
#include <exception>

using namespace std;
struct Database
{
    //Create the constructor
    private:
    Database(){
        static int instance_cnt = 0;
        if (++instance_cnt > 1)
        {
            throw exception();
        }
        
    }
};


// struct Entity{
//     static int x,y;

//     static void Print(){
//         std::cout << x << ", " <<y <<std::endl;
//     }
    
// };

// //Define a link to variables
// int Entity::x;
// int Entity::y;

// int main(int argc, char const *argv[])
// {
//     Entity::x = 2;
//     Entity::y = 4;

//     Entity::x = 5;
//     Entity::y = 6;

//     Entity::Print();
//     Entity::Print();
    
//     return 0;
// }

// Entity *e1 = new Entity;
    // e1->x = 4;
    // e1->y = 6;

    // e1->Print();
    // delete[] e1;
    // e1 = NULL;
