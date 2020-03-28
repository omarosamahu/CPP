#include <iostream>
#include <vector>
#include <array>

template<class T>
class CircularBuffer{
    private:
    int length;
    int size = 0;
    std::vector<T> buff;
    public:
    CircularBuffer(int l):length(l){
        buff.resize(l);
        std::cout << "A buffer created with "<<l<<" elements\n";
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
        
        if(buff.size() >= length){
            pop();
            buff.push_back(item);
        }
        else{
            buff.push_back(item);
        }
    }
    void pop(){
        T e = buff[0];
        buff.erase(buff.begin());
        std::cout << "poped element is "<< e <<"\n";
        //return e;
    }
    void printBuffer(){
        for(auto &item:buff){
            std::cout << item <<" ";
        }
        std::cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    CircularBuffer<int> b(3);
    b.push(12);
    b.push(13);
    b.push(14);
    b.push(15);
    b.push(16);

    b.printBuffer();

}
