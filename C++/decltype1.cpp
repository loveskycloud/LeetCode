#include <iostream>

using namespace std;

auto add(int a, int b)->decltype(a, b) {

    return a + b;
}

int main()
{

    return 0;
}

