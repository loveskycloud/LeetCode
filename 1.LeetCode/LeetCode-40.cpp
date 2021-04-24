#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    #define swap(a, b) { \
        __typeof(a) __temp = a; \
        a = b; b = __temp;  \
    }

    int find(vector<int> &arr, int l, int r) {
        while (l < r) {
            while (l < r && arr[l] <= arr[r]) {r--;}
            swap(arr[l], arr[r]);
            while (l < r && arr[l] <= arr[r]) {l++;}
            swap(arr[l], arr[r]);
        }
        return l;
    }

    int quick_select(vector<int> &arr, int l, int r, int k) {
        if (l == r) return arr[l];
        int mid = find(arr, l, r);
        int ans = 0;
        if (mid == k - 1) {
            return arr[mid];
        } else if (mid < k - 1) {
            ans = quick_select(arr, mid, r, k);
        } else {
            ans = quick_select(arr, l, mid - 1, k);
        }
        return ans;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        quick_select(arr, 0, arr.size() - 1, k);
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    Solution a;
    for (auto e : a.getLeastNumbers(arr, k)) {
        cout << e << " ";
    }
    cout << endl;
    

    return 0;
}

