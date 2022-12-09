#include <iostream>
#include <vector>

/**
 * 题意：盗窃团伙2
 * 分析：本质上是一个DFS的问题
 * 由于所有隧道可以同时修建，因此只需挑选隧道路径（即源点到终点的路径）中 修建时间最长 的即可
 */

using namespace std;

const int MAX_SIZE = 1e5,
        INF = 0x7fffffff;

struct Node {
    int v, w;   // 邻接顶点与边权
};

vector<Node> Adj[MAX_SIZE]; // 定义邻接表

int n, m;   // 顶点数 与 边数

int ans = INF;

void dfs(int u, int cost) {
    if (u == n) {   // 可达n号枢纽
        ans = min(ans, cost);   // 取最小者
        return;
    }
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i].v, w = Adj[u][i].w;
        dfs(v, max(w, cost));   // 取建造时间最长的隧道
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Node node; node.v = v; node.w = w;
        Adj[u].push_back(node);
    }
    dfs(1, 0);
    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << "How lucky!" << endl;
    }
}