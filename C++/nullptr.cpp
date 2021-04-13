#include <iostream>

using namespace std;

#ifdef CPP
#define NULL 0
#else

#endif

void f(int x) {
    cout << x << endl;
}

void f(int *x) {
    cout << x << endl;
}

int main()
{
    f(NULL);

    return 0;
}

