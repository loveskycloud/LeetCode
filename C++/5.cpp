#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n, m, s;
int arr[1005][1005];
int ans[1005];

struct node {
    int now, dist;
    bool operator<(const node &b) const {
        return this->dist > b.dist;
    }
};


int main()
{
    cin >> n >> m >> s;
    memset(arr, 0x3f, sizeof(arr));
    memset(ans, 0x3f, sizeof(ans));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(c, arr[a][b]);
    }

    priority_queue<node> que;
    que.push({s, 0});

    while (!que.empty()) {
        node t = que.top();
        que.pop();
        if (ans[t.now] != 0x3f3f3f3f) continue;
        ans[t.now] = t.dist;
        for (int i = 1; i <= n; i++) {
            if (arr[t.now][i] != 0x3f3f3f3f) {
                que.push({i, t.dist + arr[t.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3f3f3f3f) {
            cout << ans[i];
        } else {
            cout << 0x7fffffff;
        }
    }
    return 0;
}

