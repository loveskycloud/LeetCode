#include <iostream>
#include <time.h>

using namespace std;

class B;
class C;
class D;
class E;
class F;

class A {
public :
    class IVisitor {
    public:
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
        virtual void visit(F *) = 0;
    };
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    virtual ~A(){}
};

class B : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class C : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class D : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class E : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class F : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class OutputVisitor : public A::IVisitor {
public : 
    virtual void visit(A *obj) {
        cout << "this is a father class A" << endl;
    }
    virtual void visit(B *obj) {
        cout << "this is A class B object" << endl;
    }
    virtual void visit(C *obj) {
        cout << "this is A class C object" << endl;
    }
    virtual void visit(D *obj) {
        cout << "this is A class D object" << endl;
    }
    virtual void visit(E *obj) {
        cout << "this is A class E object" << endl;
    }
    virtual void visit(F *obj) {
        cout << "this is A class F object" << endl;
    }

};

int main()
{

    srand(time(0));
    A *arr[10];
    int n = 10;
    for (int i = 0; i < n; i++) {
        switch(rand() % 5) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
            case 4: arr[i] = new F(); break;
        }
    }
    OutputVisitor vis1;
    for (int i = 0; i < n; i++) {
        arr[i]->Accept(&vis1);
    }

    return 0;
}

