#include <iostream>

using namespace std;

#define maxn 5000

int s[maxn];
int head, tail;
int q[maxn + 5];
int ans;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1];

    head = tail = 0;
    ans = s[1];
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[i] < s[q[tail - 1]]) tail--;
        q[tail++] = i;
    }
    cout << ans << endl;
    return 0;
}

