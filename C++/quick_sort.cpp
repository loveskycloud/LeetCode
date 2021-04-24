#include <iostream>

using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

void qsort(int arr[], int l, int r) {
    if (l >= r) return ;
    int x = arr[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do ++i; while (arr[i] < x);
        do --j; while (arr[j] > x);
        if (i < j) swap(arr[i], arr[j]);
    }
    qsort(arr, l, j), qsort(arr, j + 1, r);
}

int temp[1000];

void merage_sort(int arr[], int l, int r) {
    if (l >= r) return ;
    int mid = l + r >> 1;
    merage_sort(arr, l, mid), merage_sort(arr, mid + 1, r);
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int i = l, j = 0; i <= r; i++, j ++) arr[i] = temp[j];
}

int main()
{
    int arr[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
#ifdef _D
    cout << "quick_sort" << endl;
    qsort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
#else
    cout << "merage_sort" << endl;
    merage_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif

    return 0;
}

