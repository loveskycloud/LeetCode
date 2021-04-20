#include <iostream>
#include <time.h>

using namespace std;

int arr[100000];

void downUpdate(int *arr, int n, int ind) {
    while (ind << 1 <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
}

void heap_sort(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        downUpdate(arr, n, i);
    }
    for (int i = 1; i <= n; i++) {
        swap(arr[1], arr[n - i + 1]);
        downUpdate(arr, n - i, 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    heap_sort(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

