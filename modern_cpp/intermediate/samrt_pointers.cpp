#include <iostream>
#include <memory>
#include <assert.h>

using std::make_shared;
using std::make_unique;
using std::weak_ptr;
using std::unique_ptr;
using std::shared_ptr;
using std::cout;
using std::endl;

struct Obj
{
    int id;
    float val;
    //create a constuctor
    Obj(int a,float b):
    id {a},val{b}{

    }
    ~Obj(){
        cout << "This is a destuctor" << endl;
    }
};

auto getObj() -> unique_ptr<Obj>{
    return make_unique<Obj>(10,3.14f);
}
int main(int argc, char const *argv[])
{   
    /*
    shared pointers
    */
//    auto sp = unique_ptr<int>{};
//    assert(!sp); //This means that the pointer is not a valid pointer 
   
      auto sp = make_shared<int>(123);
      auto wp = weak_ptr<int>{sp}; //Intialize a weak ptr with the value of shared ptr


      assert(sp);
      assert(sp.use_count()==1);
      assert(sp.unique());
      auto sp2 = sp; // u can copy the shared pointer
      assert(sp.use_count()==2);
      assert(!sp.unique());
      assert(sp2.use_count()==1);
      assert(!sp2.unique());


   
     

}

    /*
    unique pointers
    
    // auto sp =  make_unique<Obj>(10,3.14f);
    // if(sp){
    //     cout << "sp owns the object" << endl;
    // }
    // auto sp2 = std::move(sp);
    // if(sp2){
    //     cout << "sp2 owns the object" << endl;
    // }
    //  cout << obj->id << " " << obj->val << " " << endl;
    // cout << sp2->id << " " << sp2->val << " " << endl;
    // return 0;

    */
