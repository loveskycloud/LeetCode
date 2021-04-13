#include <iostream>
#include <string.h>
#include <string>

using namespace std;

template <typename T, typename U>
auto add(T a, U b) ->decltype(a + b) {

    return a + b;
}

auto func(int x) ->int {
    return x;
}
template <typename T, typename U> 
auto Func(T a, U b) ->decltype(a + b) {
    return a + b;
}


int main()
{
    int a = 4;
    int b = 6;
    cout << Func(3, 4.8) << endl;
    return 0;
}

