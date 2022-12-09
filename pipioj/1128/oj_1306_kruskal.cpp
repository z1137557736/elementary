#include <iostream>
#include <vector>

/**
 * 题意：盗窃团伙2
 * 分析：本质上是一个DFS的问题
 * 由于所有隧道可以同时修建，因此只需挑选隧道路径（即源点到终点的路径）中 修建时间最长 的即可
 */

using namespace std;

const int EDGE_MAX_SIZE = 2e5 + 10, // 边最大个数
MAX_SIZE = 1e5 + 2;   // 顶点的最大个数

struct Node {
    int u, v, w;    // w为边权
} edge[EDGE_MAX_SIZE];

int father[MAX_SIZE];

int findFather(int x) {
    if (father[x] == x) return x;
    else {
        int f = findFather(father[x]);  // 压缩路径
        father[x] = f;
        return f;
    }
}

// 升序排序
bool cmp(Node a, Node b) {
    return a.w < b.w;
}

void kruskal(int n, int m) {
    // 1. 自成连通分量 + 排序
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    sort(edge, edge + m, cmp);
    // 2. 查找
    for (int i = 0; i < m; i++) {
        int fa = findFather(edge[i].u);
        int fb = findFather(edge[i].v);
        // 3. 合并
        if (fa != fb) {
            father[fb] = fa;
            if (findFather(1) == findFather(n)) {
                cout << edge[i].w << endl;
                return;
            }
        }
    }
    cout << "How lucky!" << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    kruskal(n, m);
    return 0;
}