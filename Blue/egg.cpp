/*************************************************************************
	> File Name: egg.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 May 2021 08:51:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

const int maxn = 1000;

int dp[maxn][maxn];

int main() {
    
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            dp[i][j] = j;
        }
    }

    for(int i = 2; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
            }
        }
    }
    
    cout << dp[3][1000] << endl;
    return 0;
}
