#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;


int main()
{
    
    vector<string> vec;
    string str = "hello word"; 
    vec.push_back(str);
    cout << str << endl;
    cout << move(str) << endl; 
    vec.push_back(move(str));
    cout << "di dai qi"  << endl;
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

