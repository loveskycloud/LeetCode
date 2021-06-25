/*************************************************************************
	> File Name: split.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 May 2021 10:31:28 AM CST
 ************************************************************************/

#include<iostream>
#include <memory>
#include <vector>
#include <string.h>
using namespace std;

void split(string str) {
    str = str.substr(1, str.size() - 2);
    vector<string> vec;
    char *temp = const_cast<char *>(str.c_str());
    char *ans = strtok(temp, ",");
    while (ans != nullptr) {
        vec.push_back(ans); 
        ans = strtok(NULL, ",");
    }
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cin >> str;
    split(str);

    return 0;
}
