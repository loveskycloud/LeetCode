#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct node {
    int e, dist, next;
};

struct point {
    int now, dist;
    bool operator <(const point &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, ans[10005], head[10005];
node edge[600005];


int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].e = b;
        edge[i].dist = c;
        edge[i].next = head[a];
        head[a] = i;
    }
    return 0;
}

