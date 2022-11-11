#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * Floyd算法（"弗洛伊德算法"）用于解决全源最短路径，即求任意两点之间的最短路径长度
 * 时间复杂度为O(n^3)
 */

const int INF = 0x3ffffff;
const int MAX_SIZE = 200;
// 顶点数、边数
int n, m;
// 定义邻接矩阵 全源最短路径
int dis[MAX_SIZE][MAX_SIZE];

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] <dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    fill(dis[0], dis[0] + MAX_SIZE * MAX_SIZE, INF);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        dis[a][b] = w;
    }
    Floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}