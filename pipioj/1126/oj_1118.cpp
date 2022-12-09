#include <iostream>

using namespace std;

/**
 * <h2>城城通</h2>
 * 分析：本质上是一个最小生成树的问题，对于已修建的路，只需令其cost为0即可。
*/
const int MAX_SIZE = 500,   // 顶点个数
INF = 0x7fffffff;   // 无穷大
int d[MAX_SIZE];   // 生成树到其余顶点的最小代价
int D[MAX_SIZE][MAX_SIZE];  // 邻接矩阵
bool vis[MAX_SIZE] = {false};   // 标记顶点是否访问
int n, ans;  // 当前顶点个数

// prim
void prim(int s) {
    fill(vis, vis + MAX_SIZE, false);
    fill(d, d + MAX_SIZE, INF);    // 抹边
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, min = INF;
        for (int j = 1; j <= n; j++) {   // 定位
            if (d[j] < min && !vis[j]) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) return;    // 非连通图
        vis[u] = true;  // 并入
        ans += d[u];
        for (int v = 1; v <= n; v++) {   // 保持
            if (G[u][v] != INF && !vis[v] && d[u] + G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
}

int main() {
    while (cin >> n) {
        if (n == 0) return 0;
        fill(G[0], G[0] + MAX_SIZE * MAX_SIZE, INF);
        int m = n * (n - 1) / 2;
        for (int i = 0; i < m; i++) {
            int u, v, w, t;
            cin >> u >> v >> w >> t;
            if (t == 1) w = 0;  // 已修建的通道，成本为0
            G[u][v] = w;
            G[v][u] = w;
        }
        ans = 0;
        prim(1);
        cout << ans << endl;
    }
}

