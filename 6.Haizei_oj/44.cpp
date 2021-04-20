#include <iostream>
#include <limits.h>
using namespace std;

int dp[1000];
int arr[10000];
int ans = 0;
int len[10000];

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l; 
    int mid = l + r >> 1;

    if (arr[mid] < x) {
        return bs(arr, mid + 1, r, x);
    }
    return bs(arr, l, mid, x);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        len[i] = INT_MAX;
    }
    len[++ans] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans, arr[i]);
        len[dp[i]] = arr[i];
        ans = max(dp[i], ans);
    }

    cout << ans << endl;

    return 0;
}

