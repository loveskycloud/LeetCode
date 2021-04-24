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
    for (int i = 0; i < vec.size(); i++) 
    {
        pop_heap(vec.begin(), vec.end() - i, less<>());
    }
    
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

