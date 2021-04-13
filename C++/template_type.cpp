#include <iostream>
#include <string.h>
#include <functional>

using namespace std;

template<typename T>
void my_swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    cout << sizeof(c) << endl; 
    c = a;
    a = b;
    b = c;
    return ;
}

void func(void (*p)(int &, int &), int &a, int &b) {
    p(a, b);
}

template<typename T>
struct my_remove_reference {
    typedef T type;
};

template<typename T>
struct my_remove_reference<T &> {
    typedef T type;
};

template<typename T>
struct my_remove_reference<T &&> {
    typedef T type;
};

void func(int &a) {
    cout << "left value" << endl;
}

void func(int &&a) {
    cout << "right value" << endl;
}

int main()
{
    int a = 3;
    int b = 5;
   
        

    func(move(a));
    func(a);
    func(4);

    typename my_remove_reference<int>:: type c;
    typename my_remove_reference<int &>:: type d;
    typename my_remove_reference<int &&>:: type f;


    return 0;
}

