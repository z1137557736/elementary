#include <iostream>
#include <queue>

using namespace std;

char field[110][110];    // 油田矩阵
int n, m;   // 矩阵范围

// 定义方向数组 分别为：上、下、左、右、左上、左下、右上、右下
int dir[8][2] = {{-1, 0},{1, 0},{0, -1},{0, 1},{-1, -1},{1, -1},{-1, 1},{1, 1}};

bool dfs(int x, int y) {    // 以[x,y]为起始点
    field[x][y] = '*';  // 标记为非油井
    for (int i = 0; i < 8; i++) {
        int nexti = x + dir[i][0];
        int nextj = y + dir[i][1];
        // 若坐标非法，非石油，已入队，则跳过此次循环
        if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m
            || field[nexti][nextj] == '*') continue;
        dfs(nexti, nextj);
    }
}

// 枚举每一个顶点，查询图的连通分量的个数，即土地上油田的数目
void dfsTravel() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '@') {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 || m == 0) return 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }
        dfsTravel();
    }
}