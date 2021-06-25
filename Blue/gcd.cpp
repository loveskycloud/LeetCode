/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 08:01:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcd(int a, int b, int gcd) {
    return a * b / gcd;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcd(a, b, gcd(a, b)) << endl;
    return 0;
}
