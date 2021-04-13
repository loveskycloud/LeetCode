#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

#define maxn 100005

int arr[maxn];
int n, k;

int main()
{
    cin >> n >> k;
    assert(n >= 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans  = 0;
    for (int i = 0; i < n; i++) {

        int temp = n;
        for (int j = n - 1; j > i; j--) {
            if (arr[j] && k / arr[j] >= arr[i] || !arr[j] && k > 0) {
                ans += j - i;
                break;
            } else {
                continue;
            }
        }

    }

    cout << ans << endl;

    return 0;
}

