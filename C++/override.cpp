#include <iostream>

using namespace std;

struct A {
    virtual void func1() {
        cout << "Class A func1" << endl;
    }
    void funcl() {
        cout << "Class A func ai ou" << endl;
    }
};

struct B : A {
    void funcl() override {
        cout << "Class B func ai ou" << endl;
    }

};


int main()
{
    B b;
    A *a = &b;
    a->funcl(); // cheng yuan fang fa gen zhe lei zou, 
    
    return 0;
}

