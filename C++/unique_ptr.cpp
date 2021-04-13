#include <iostream>
#include <memory>
using namespace std;

class B {
    char *c;
public :
    void do_echo() {

        cout << "666" << endl;
    }
    B(){
        c = new char(1);
        cout << "I am come!\n" << endl;
    }
    ~B(){ 
        delete c;
        cout << "I am free!\n" << endl;
    }
    B(const B &b) {
        cout << "?" << endl;
    }
    void operator=(const B &n) {
        cout << "." << endl;
    }
};

void do_echo(unique_ptr<B>) {
    
}

int main()
{
    /*
    unique_ptr<B> e(new B());
    unique_ptr<B> c = make_unique<B>();
    auto a = make_unique<B>();
    e->do_echo();
    cout << "---" << endl;
    unique_ptr<B> d = move(e);
    e->do_echo();
*/
    cout << "start---" << endl;
    auto ceshi = make_unique<B>();
    do_echo(move(ceshi));
    ceshi->do_echo();
    auto c = make_unique<B>();
    char *b = new char(2);
    delete b;
    delete b;
    return 0;
}

