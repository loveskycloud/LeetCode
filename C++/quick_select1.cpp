#include <iostream>

using namespace std;

int func(int arr[], int left, int right) {
    int l = left, r = right;
    while (l < r) {
        while (l < r && arr[l] < arr[r]) r--;
        swap(arr[l], arr[r]);
        while (l < r && arr[l] < arr[r]) l++;
        swap(arr[l], arr[r]);
    }
    return l;
}

int quick_select(int arr[], int l, int r, int k) {
    if (l == r) return arr[l];
    int mid = func(arr, l, r);
    int ans = 0;
    if (mid == k - 1) {
        return arr[mid];
    } else if (mid < k - 1) {
        ans = quick_select(arr, mid + 1, r, k);
    } else {
        ans = quick_select(arr, mid - 1, r, k);
    }

    return ans;
}

int main()
{
    return 0;
}

