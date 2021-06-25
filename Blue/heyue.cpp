/*************************************************************************
	> File Name: heyue.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 May 2021 02:37:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

const int maxn = 2020;

int isprime[maxn] = {0};

void init() {
    for (int i = 2; i <= 2020; i++) {
        if (!isprime[i]) isprime[++isprime[0]] = i;
        for (int j = 1; j <= isprime[0]; j++) {
            if (isprime[j] * i > maxn) break;
            isprime[i * isprime[j]] = i;
            if (isprime[j] % i == 0) break;
        }
    } 
}

int main() {
    
    init();
    cout << maxn - isprime[0] - 1 << endl;
    
    return 0;
}
