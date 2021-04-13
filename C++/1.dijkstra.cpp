#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct node {
    int now, dist;
    bool operator<(const node &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, dis[1005][1005], ans[1005];

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
    }
    priority_queue<node> que;
    que.push({s, 0});
    while (!que.empty()) {
        node t = que.top();
        que.pop();
        if (ans[t.now] != 0x3f3f3f3f) continue;
        ans[t.now] = t.dist;
        for (int i = 1; i <= n; i++) {
            if (dis[t.now][i] != 0x3f3f3f3f) {
                que.push({i, t.dist + dis[t.now][i]});
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

