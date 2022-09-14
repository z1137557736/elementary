#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
/**
 * SPFA(Shortest Path Faster Algorithm)
 * 只有当顶点u的d[u]的值发生改变时，从d[u]出发的邻接边的边权也要重新计算
 * 支持负边权
 */

struct Node {
    int v, w;
};

const int INF = 0x3fffffff;
const int MAX_SIZE = 1000;
int n, m;
vector<Node> Adj[MAX_SIZE];
int d[MAX_SIZE];
bool inq[MAX_SIZE] = {};

// 时间复杂度为O(kE), k为常数、E为边数
bool SPFA(int s) {
    queue<int> q;
    fill(d, d + n, INF);
    d[s] = 0;
    q.push(s);
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 标记为未在队列中，允许同一顶点入队多次
        inq[s] = false;
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i].v,
                w = Adj[u][i].w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}


int main() {
    int s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        // 邻接表版 有向图
        Node node;
        node.v = b;
        node.w = w;
        Adj[a].push_back(node);
    }
    SPFA(s);
    for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
}