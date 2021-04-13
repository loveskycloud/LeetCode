#include <iostream>

using namespace std;

template <typename T, typename ARGS ...args> class TEST;
template <typename T, typename ARGS ...args> 
class TEST<T> {
    public : 
        typedef T getT;
        typedef T finalT;
};




int main()
{
    TEST<int, double, float> e; 


    return 0;
}

