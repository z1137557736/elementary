#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;   // 最大顶点个数

int inDegree[MAX_SIZE] = {};  // 顶点入度数
int D[MAX_SIZE][MAX_SIZE] = {0};  // 邻接矩阵

bool topological(int n) {
    int sum = 0;    // 拓扑序列中的顶点个数
    queue<int> q;
    // 1. 入队
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop(); // 队首元素出队
        sum++;  // 保持sum为拓扑序列中的顶点个数
        for (int v = 1; v <= n; v++) {
            if (G[u][v] != 0) { // 存在u指向v的有向边
                // 2. 抹边
                inDegree[v]--;
                // 3. 再入队
                if (inDegree[v] == 0) q.push(v);
            }
        }
    }
    return sum == n;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;    // 存在边
        inDegree[v]++;  // 顶点v的入度加1
    }
    // 有环输出yes
    if (!topological(n)) cout << "yes" << endl;
    else cout << "no" << endl;
}