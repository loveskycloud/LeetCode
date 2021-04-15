#include <iostream>

using namespace std;

void downUpdate(int *arr, int n, int ind) {
    while (ind << 1 <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] >  arr[temp]) temp = r;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
}
 
void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main()
{
    return 0;
}

