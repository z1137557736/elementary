#include <cstdio>

int const MAX_SIZE = 1000;

typedef int VType;

/**
 * （Depth First Search）深度优先搜索
 *
 * 分为 邻接矩阵版 与 邻接表版
 */

/** 邻接矩阵版 遍历图 开始  **/
VType G[MAX_SIZE][MAX_SIZE];

int n;

bool vis[MAX_SIZE] = {};

void DFS(int v) {
    printf("%d", v);
    vis[v] = true;
    for (int i = 0; i < n; i++) {
        if (G[v][i] > 0 && !vis[i]) {
            DFS(i);
        }
    }
}

void traverseGraph() {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) DFS(i);
    }
}

int main() {
    // 初始化邻接矩阵的数据
    n = 2;
    G[0][1] = 1;
    G[1][0] = 1;
    traverseGraph();
    return 0;
}