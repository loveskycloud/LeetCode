/*************************************************************************
	> File Name: Square.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 May 2021 09:46:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int dp[8][8];

int main() {
   
    int ans = 0;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            dp[i][j] = ++ans;
        }
    }
    
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            //cout << dp[i][j] << " ";
            printf("%2d ", dp[i][j]);
        }
        cout << endl;
    }
    return 0;
}
