#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    string str = "hello";
    vector<string> vec;
    vec.push_back(move(str));
    cout << str[0] << endl;
    cout << vec[0] << endl;


    return 0;
}

