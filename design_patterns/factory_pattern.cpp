#include <iostream>

enum VehicleType{
    VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler
};

class Vehicle{
    public:
        virtual void printVehicle()=0;
        static Vehicle* Create(VehicleType type);
};

class TwoWheeler : public Vehicle{
    public:
          void printVehicle(){
              std::cout << "I am two wheeler" << std::endl;
          }
};

class ThreeWheeler : public Vehicle{
    public:
        void printVehicle(){
            std::cout << "I am three wheeler" << std::endl;
        }
};

class FourWheeler : public Vehicle{
    public:
        void printVehicle(){
            std::cout << "I am four wheeler" << std::endl;
        }
};

//Factory Method
Vehicle *Vehicle::Create(VehicleType type){
    if (type == VT_TwoWheeler)
    {
        return new TwoWheeler;
    }
    else if (type == VT_ThreeWheeler)
    {
        return new ThreeWheeler;
    }
    else if(type == VT_FourWheeler){
        return new FourWheeler;
    }
    else
    {
         return NULL;
    }
    
    
    
}

class Client{
    public:
        Client(VehicleType type){
            pVehicle = Vehicle::Create(type);
            
        }
        ~Client(){
            delete[] pVehicle;
            pVehicle = NULL;
            std::cout << "I have been destructed" << std::endl;
        }

        Vehicle *getVehicle(){
            return pVehicle;
        }
    private:
        Vehicle *pVehicle;
};

int main(int argc, char const *argv[])
{
    Client *c = new Client(VT_TwoWheeler);
    //Create A vehicle pointer to refer to getVehicle function
    Vehicle *v = c->getVehicle();
    v->printVehicle();
    
    return 0;
}
