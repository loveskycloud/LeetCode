#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


int main()
{
    
    vector<int> vec{2, 3, 10, 4, 1, 6, 9, 0};
    
    make_heap(vec.begin(), vec.end(), less<>());
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
    pop_heap(vec.begin(), vec.end(), less<>());
    
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;

    cout << vec.back() << endl;

    return 0;
}

