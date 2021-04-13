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

vector<int> a, w;
int main() {
    int n, m;
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &temp);
        w.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(w.begin(), w.end());
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        cout <<  lower_bound(w.begin(), w.end(), a[i]) - w.begin();
        int *index = &w[0];
        if ((int)(index - &w[0])  < 0 || (int)(index - &w[0]) >= w.size()) {
            continue;
        }
        sum ++;
        w.erase(w.begin() + (int)(index - &w[0]));
    }

    cout << sum << endl;
    return 0;
}

