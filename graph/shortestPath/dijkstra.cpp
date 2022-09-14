#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 狄杰斯特拉算法
 * 求解单源最短路径
 * 分为邻接矩阵版 与 邻接表版
 */

const int INF = 0x3fffffff;
const int MAX_SIZE = 1000;

// 定义邻接表
struct Node {
    int v, w;
};
vector<Node> Adj[MAX_SIZE] = {};

// 顶点数和边数
int n, m;
// 定义邻接矩阵
int G[MAX_SIZE][MAX_SIZE];
// 记录源点到达各个顶点的最短路径长度
int d[MAX_SIZE];
// 标识顶点是否被访问
bool visit[MAX_SIZE] = {};

/**
 * dijkstra的算法实现步骤
 * 时间复杂度为O(V^2)
 * 1. d[]初始值为INF，且令d[s] = 0，其中s为源点，并循环执行以下步骤
 * 2. 从d[]中挑选最小的最短路径长度的顶点u(未被访问的)
 * 3. 若u = -1, 退出循环
 * 4. 标记顶点u已访问，并开放其所有边，且以d[u]为中介点，可使得d[v] = min(d[u] + G[u][v], d[v])最优
 *
 * 注意：对于已访问的顶点，此时已处于源点到该顶点的最短路径长度
 */
void dijkstra(int s) {
    fill(d, d + n, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int k = 0; k < n; k++) {
            if (!visit[k] && d[k] < MIN) {
                u = k;
                MIN = d[k];
            }
        }
        if (u == -1) return;
        visit[u] = true;
        // 邻接矩阵版
        /*for (int v = 0; v < n; v++) {
            if (G[u][v] > 0 && !visit[v] && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }*/
        // 邻接表版
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v,
                w = Adj[u][j].w;
            if (!visit[v]) {
                d[v] = min(d[v], d[u] + w);
            }
        }
    }
}

/**
6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
0 1 5 3 4 6
*/
int main() {
    int s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        // 邻接矩阵版 无向边(由互逆的两条有向边组成)
        G[a][b] = w;
        G[b][a] = w;
        // 邻接表版 有向图
        Node node;
        node.v = b;
        node.w = w;
        Adj[a].push_back(node);
    }
    dijkstra(s);
    for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
}