#include <iostream>

using namespace std;

int arr[1000];
int n;

void quick_sort(int arr[], int l, int r) {
    if (l >= r) return ;
   int x = arr[l + r >> 1]; 
   int i = l - 1, j = r + 1;
   while (i < j) {
       do i++; while (arr[i] < x);
       do j--; while (arr[j] > x);
       if (i < j) swap(arr[i], arr[j]);
   }
   quick_sort(arr, l, j), quick_sort(arr, j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 1, n);
    
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}

