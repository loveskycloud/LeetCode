#include <iostream>
#include <functional>
using namespace std;


template<int x>
struct Isodd {
    constexpr static int r = x % 2;
};

void func(int x, int y, int z) {
    cout << x + y << " is a number" << endl;
    cout << z << endl;
}


int main()
{
   function<void(int)> f = bind(func, 123, std::placeholders::_1, std::placeholders::_2);
    f(456);
    return 0;
}

