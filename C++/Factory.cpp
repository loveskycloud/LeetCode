#include <iostream>

using namespace std;

class Car {
    
public :

    int wheel_cnt, color, brand;

};

class ICar {
public :
    class IFactory {
        public z:
            virtual ICar *create() = 0;
    }

private :
    ICar() {}
    ~ICar() {}
};

class BenzCar : public ICar {
    BenzCar() {}
public :

};

class BmwCar : public ICar {
    BmwCar() {}
public :
    class Factory : public ICar::Factory{
        virtual ICar *create() {
            return new BmwCar();
        }
    }
    virtual void run() {
        cout << "BmwCar run" << endl;
    }

};

class AudiCar : public ICar {
    AudiCar() {}
public :
};

int main()
{

    return 0;
}

