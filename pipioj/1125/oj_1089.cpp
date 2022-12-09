#include <iostream>
#include <queue>

using namespace std;

// 4个定义 - 迷宫，方向数组，Node用于记录当前位置，road记录路径

const int n = 5, m = 5; // 迷宫范围, n为行的范围，m为列的范围

int maze[n][m];

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 方向数组 - 右下左上

struct Node {
    int i, j;   // i为行号，j为列号
} road[n][m];   // road 用于记录路径（上一步所在的位置）

bool inq[n][m] = {false};   // 顶点是否入队标识

// 路径输出
void dfs(int i, int j) {
    if (i == -1) return;    // 递归边界
    dfs(road[i][j].i, road[i][j].j);
    printf("(%d, %d)\n", i, j);
}

// 假设迷宫的左上角为起点，右下角为终点
void bfs() {
    Node s;  // 起点
    s.i = s.j = 0;
    road[0][0].i = road[0][0].j = -1;   // 起点的上一步为(-1,-1)，作为dfs的递归边界
    queue<Node> q;
    inq[0][0] = true;
    q.push(s);
    while(!q.empty()) {
        Node f = q.front(); q.pop();    // 队首元素出队
        if (f.i == n - 1 && f.j == m - 1) { // 找到出口
            dfs(f.i, f.j);
            return;
        }
        // 四个方向
        Node node;
        for (int i = 0; i < 4; i++) {
            int nexti = f.i + dir[i][0];
            int nextj = f.j + dir[i][1];
            // 若坐标有效、非墙壁或为入队
            if (0 <= nexti && nexti < n && 0 <= nextj && nextj < m
                && !maze[nexti][nextj] && !inq[nexti][nextj]) {
                node.i = nexti;
                node.j = nextj;
                inq[node.i][node.j] = true;   // 标记为已入队
                q.push(node);   // 下一个坐标点入队
                // 记录路径
                road[node.i][node.j].i = f.i;
                road[node.i][node.j].j = f.j;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maze[i][j];
        }
    }
    bfs();
}