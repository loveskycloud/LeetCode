#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<limits.h>
using namespace std;

int a[10000];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int>ans;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        ans.push_back(t);
    }
    sort(a, a + n);
    sort(ans.begin(), ans.end());
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int t = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
        if(t != 0) {
            ans.erase(ans.begin() + t - 1);
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
