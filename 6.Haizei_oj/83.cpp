#include <iostream>

using namespace std;

int func(int s, int left, int cnt) {
    if (left == 0) {
        if (cnt == 0) {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left; i++) {
        ans += func(i, left - i, cnt - 1);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m);
    return 0;
}

