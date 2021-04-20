#include <iostream>

using namespace std;
int arr[10000];
int temp[10000];

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
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        temp[k++] = arr[j++];
    }
    for (int i = l, j = 0; i <= r; j++,i++) arr[i] = temp[j];
}


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) { 
        cin >> arr[i];
    }
    merage_sort(arr, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

