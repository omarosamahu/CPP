#include <iostream>
#include <vector>
#include <set>

template<class T>
class PriorityQueue{
    private:
    int length;
    int size = 0;
    std::set<T,std::greater<T>> buff;
    public:
    PriorityQueue(int l):length(l){
        //buff.resize(l);
        std::cout << "Priority Queue has created\n";
        }
    bool empty(){
        if(buff.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void push(T item){
        buff.insert(item);
    }
    void pop(){
        if(!empty()){
            T e = *buff.begin();
            buff.erase(*buff.begin());
            std::cout << "poped element is "<< e <<"\n";
        }

        else{
            std::cout << "There is no element to be popped\n";
        }
        //return e;
    }
    T top(){
        return *buff.begin();
    }
    int getSize(){
        return buff.size();
    }
    void printBuffer(){
        for(T item:buff){
            std::cout << item <<" ";
        }
        std::cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    PriorityQueue<int> *b = new PriorityQueue<int>(3);
    b->push(12);
    b->push(13);
    b->push(14);
    b->push(15);
    b->push(16);
    // b->push(17);
    // b->push(18);
    // b->push(19);
    // b->pop();
    // b->pop();
    // b->pop();
    // b->pop();
    b->printBuffer();
    b->pop();
    b->pop();
    b->pop();
   
    b->printBuffer();
    b->pop();
    b->printBuffer();

}
