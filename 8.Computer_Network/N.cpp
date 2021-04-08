#include <iostream>

using namespace std;

int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {
        if (left_num == 0) {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        ans += func(i, left_num - i, left_cnt - 1);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}

