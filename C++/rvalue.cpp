#include <iostream>

using namespace std;

void f(int &x) {
    cout << "left value" << endl;
}

void f(int &&x) {
    cout << "right value" << endl;
}

int main()
{
    
    int n = 123;
    f(move(n++));
    f(++n);
    
    
    return 0;
}

