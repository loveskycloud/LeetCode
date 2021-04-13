#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1000
int arr[maxn];
int book[maxn];
int main()
{
    int n, target;
    int k;
    cin >> n;
    cin >> target;
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    while (k--) {

    int l = 0, r = n;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] <= target && book[mid] == 0) {
            l = mid + 1;
        } else if (arr[mid] > target || book[mid] == 1) {
            r = mid - 1;
        }
    }
    cout << ": " << k << endl;
    cout << r << endl;
    cout << arr[r] << endl;
    book[r] = 1;
    }
    return 0;
}

