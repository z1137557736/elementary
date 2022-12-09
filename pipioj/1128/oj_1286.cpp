#include <iostream>
/**
 * 题意：给定城市交通图，建立应急中心（源点），使得距离应急中心最远的城市 - 到 - 应急中心的距离最短
 * 分析：本质上是一个多源最短路径的问题
 * 算法步骤三步走
 * 1. Floyd - 记录每个源点到其余城市的最短路径
 * 2. 定位距离各个应急中心最远的城市
 * 3. 取最短距离
 */

using namespace std;

const int MAX_SIZE = 510,
        INF = 0x7fffffff;

int D[MAX_SIZE][MAX_SIZE];  // 邻接矩阵, 记录多源最短路径

int n, m;   // 顶点数 与 边数

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int dis[MAX_SIZE] = {0};  // 存放每个源点到最远城市的距离

void judgeMinDis() {
    bool flag = true;   // 应急中心是否可达所有城市
    // 2. 定位距离各个应急中心最远的城市
    for (int i = 1; i <= n; i++) {
        int max = -1;
        for (int j = 1; j <= n; j++) {
            if (D[i][j] == INF) {
                flag = false;
                break;
            }
            if (D[i][j] > max) {
                max = D[i][j];  // 保持max为源点到最远城市的距离
            }
        }
        dis[i] = max;
    }
    if (flag) {
        // 3. 取最短距离
        int u = -1, min = INF;
        for (int i = 1; i <= n; i++) {
            if (dis[i] < min) {
                min = dis[i];
                u = i;
            }
        }
        cout << u <<
        ' ' << dis[u] << endl;
    } else {
        cout << "What a pity!" << endl;
    }
}

int main() {
    cin >> n >> m;
    fill(D[0], D[0] + MAX_SIZE * MAX_SIZE, INF);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        D[u][v] = D[v][u] = w;
    }
    floyd();
    judgeMinDis();
}