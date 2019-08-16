#include <iostream>

class Singleton{
 static Singleton *instance;
    int data;
    Singleton(){
        data = 0;
    } 
 public:
    static Singleton *getInstance(){
        if (!instance)
        {
            instance = new Singleton;
        }
        return instance;
        
    }
    void setData(int data){
        this ->data = data;
    }
    int getData(){
        return this->data;
    }
    
};

Singleton *Singleton::instance =0;

int main(int argc, char const *argv[])
{
    
    Singleton *s = s->getInstance();
    std::cout << s->getData() << std::endl;
    s->setData(100);
    std::cout << s->getData() << std::endl;
    return 0;
}
