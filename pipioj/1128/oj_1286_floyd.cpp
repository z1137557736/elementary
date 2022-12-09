#include <iostream>

using namespace std;

/**
 * PIPI运货
 * 题意：本质上是一个多源最短路径的问题，只是增加了站点过路费，裸Floyd的问题
*/
const int INF = 0x7fffffff;
const int MAX_SIZE = 110;

int D[MAX_SIZE][MAX_SIZE];  // 邻接矩阵
int toll[MAX_SIZE]; // 记录各个点的过路费
int d[MAX_SIZE][MAX_SIZE];    // 记录多源最短路径

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 收取中介点k的过路费
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] + toll[k] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j] + toll[k];
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> G[i][j];
            if (G[i][j] != -1) d[i][j] = G[i][j];
            else d[i][j] = INF; // -1 设置为INF
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> toll[i];
    }
    int m;
    cin >> m;
    floyd(n);
    for (int i = 0; i < m; i++) {
        int s, e;   // 源点和终点
        cin >> s >> e;
        cout << d[s][e] << endl;
    }
}