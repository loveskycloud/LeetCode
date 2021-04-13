#include <iostream>
#include <algorithm>
#include "thread_pool.h"
using namespace std;

void func(int a, int &b) {
    cout << "func : " << a + b << endl;
    b += 100;
    return ;
}

int main()
{
    int n = 123;
    haizei::Task t(func, 23, ref(n));
    t.run();
    cout << n << endl;
    haizei::thread_pool threads;
    threads.start();

    return 0;
}

