#include <iostream>

using namespace std;

typedef void(*func)();

class A {
public:
    virtual void say() {
        cout << "666" << endl;
    }
    virtual void cool() {
        cout << "cool" << endl;
    }
    A(){}
    virtual ~A(){
        cout << "too shabi" << endl;
    }
};

int main()
{
    A a;
    ((func **)(&a))[0][0](); 
    ((func **)(&a))[0][1](); 
    ((func **)(&a))[0][2](); 
    return 0;
}

