#include <iostream>
#include <functional>


using namespace std;

struct A {
    void say() { 
        cout << this << " : saying" << endl;
    }
    void run() {
        cout << "hello world" << endl;
    }
};

void count_function_time(function<void()> &p, int &cnt) {
    p();
    cnt += 1;
    return ;
}

int main()
{
    A a;
    int cnt = 0;
    function<void()> f3 = bind(&A::run, ref(a));
    function<void()> f4 = bind(count_function_time, ref(f3), ref(cnt));
    for (int i = 0; i < rand() % 10; i ++ ) f4();
    cout << cnt << endl;
    return 0;
}

