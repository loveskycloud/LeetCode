#include <iostream>
#include <functional>
using namespace std;

auto add = [](int a, int b) {
    return a + b;
};

auto func = [](int a, int b) {
    return [=](){
        return a + b;
    };
};

auto func1() {
    int a = 3;
    return [=]() -> int {
        return a;
    };
}

int main()
{
    cout << add(3, 5) << endl;
    
    auto p = func(5, 5);
    cout << p() << endl;
    
    auto p1 = func1();
    cout << p1() << endl;

    return 0;
}

