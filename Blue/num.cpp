/*************************************************************************
	> File Name: num.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 May 2021 08:05:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        cout << (str[i] - 'a') <<  " ";
    }
    cout << endl;

    return 0;
}

