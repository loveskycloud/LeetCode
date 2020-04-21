void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *arr = (int *)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            arr[k++] = nums1[i++];
        } else {
            arr[k++] = nums2[j++];
        }
    }
    while (i < m) {
        arr[k++] = nums1[i++];
    }
    while (j < n) {
        arr[k++] = nums2[j++];
    }
    for (int i = 0; i < k; i++) {
        nums1[i] = arr[i];
    }

}
