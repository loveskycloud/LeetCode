#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> &vec, int left, int right) {
    int l = left, r = right;
    while (l < r) {
        while (l < r && vec[l] <= vec[r]) r--;
        swap(vec[l], vec[r]);
        while (l < r && vec[l] <= vec[r]) l++;
        swap(vec[l], vec[r]);
    }
    return l;
}

int quick_select(vector<int> vec, int left, int right, int k) {
    if (left == right) return vec[left];
    int mid = func(vec, left, right);
    cout << mid << endl;
    if (mid == k - 1) {
        return vec[mid];
    } else if (mid > k - 1) {
        quick_select(vec, left, mid - 1, k);
    } else {
        quick_select(vec, mid + 1, right, k - mid);
    }
    return vec[left];
}

int check(vector<int> &vec, int L, int R) {
    int l = L, r = R;
    while (l < r) {
        while (l < r && vec[l] <= vec[r]) r--;
        swap(vec[l], vec[r]);
        while (l < r && vec[l] <= vec[r]) l++;
        swap(vec[l], vec[r]);
    }
    return l;
}

int find(vector<int> &vec, int l, int r, int k) {
    if (l == r) return vec[l];
        int ans = 0;
        int mid = check(vec, l, r);
        cout << "mid " << mid << endl;
        cout << "k " << k << endl;
        cout << vec[mid] << endl;
        cout << '-' << endl;
        if (mid == k - 1) {
            cout << vec[mid] << endl;
            return vec[mid];
        }
        else if (k - 1 < mid) ans = find(vec, l, mid - 1, k);
        else ans = find(vec, mid + 1, r, k);
    return ans;
}

int main()
{
    int n, target;
    vector<int> vec;
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    cout << find(vec, 0, n - 1, target);
    return 0;
}

