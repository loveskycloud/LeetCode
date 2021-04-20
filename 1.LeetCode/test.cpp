#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> a;

int main()
{
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a.erase(2);
    cout << a.size() << endl;

    return 0;
}

