/*************************************************************************
	> File Name: to_string.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 May 2021 06:33:45 PM CST
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string str = to_string(n) + "yes";
    for (auto e : str) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
