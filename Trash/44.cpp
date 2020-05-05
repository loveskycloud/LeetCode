#include <iostream>
using namespace std;
#define MAX_N 1000
int val[MAX_N + 5];
int dp[MAX_N + 5];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        dp[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (val[i] <= val[j]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

