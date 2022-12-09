#include <iostream>

using namespace std;

const int MAX_SIZE = 1010,  // 最大顶点个数
        INF = 0x7fffffff;   // 无穷大

int G[MAX_SIZE][MAX_SIZE];  // 邻接矩阵
int d[MAX_SIZE];    // 源点到各个顶点的最短距离
bool vis[MAX_SIZE] = {false};
int n, m, a;    // 顶点数、边数和时间

int cost(int i) {
    return i % 2 == 0 ? 2 : 1;  // 偶数花费两分钟，奇数花费1分钟
}

int dijkstra(int s, int t) {
    fill(d, d + MAX_SIZE, INF);
    fill(vis, vis + MAX_SIZE, false);
    d[s] = 0; // 起点等待时间
    for (int i = 1; i <= n; i++) {
        int u = -1, min = INF;
        // 1. 定位待割据点
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) continue;    // 非连通图
        vis[u] = true;  // 2. 割据
        // 3. 保持
        for (int v = 1; v <= n; v++) {
            // 奇数的起始点边权加1，偶数的起始点边权加2
            if (G[u][v] != INF && !vis[v] && d[u] + G[u][v] + cost(u) < d[v]) {
                d[v] = d[u] + G[u][v] + cost(u);
            }
        }
    }
    return d[t];
}

int main() {
    int s, t;
    while (cin >> n >> m >> s >> t >> a) {
        fill(G[0], G[0] + MAX_SIZE*MAX_SIZE, INF);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }
        int ans = dijkstra(s, t);
        if (ans <= a) cout << "YES " << ans << endl;
        else cout << "KENG" << endl;
    }
}