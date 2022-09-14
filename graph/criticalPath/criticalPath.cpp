#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

/**
 * 关键路径（即AOE中的最长路径）
 * 其中
 * ve[k] 为事件k的最早开始时间
 * vl[k] 为事件k的最迟开始事件
 * 要想得到当前顶点k的最早开始时间ve[k]，则需知道其前驱结点的最早开始时间ve[pre] + length[r]
 * 拓扑排序则能保证访问当前顶点之时，其前驱结点必被访问
 */

struct Node {
    int v, w;
    // 带参数的构造函数
    Node(int _v, int _w) : v(_v), w(_w){};
};

const int MAX_SIZE = 1000;
// 顶点数 边数
int n, m;
// 初始化数组为0
int ve[MAX_SIZE] = {}, vl[MAX_SIZE] = {};
// 邻接表
vector<Node> Adj[MAX_SIZE];
// 各个顶点的入边
int inDegree[MAX_SIZE];
// 便于逆拓扑排序输出
stack<int> topS;

/**
 * 拓扑排序
 * @return true 为有向无环图
 */
bool topologySort() {
    // 若图为有向无环图，必有 sum === n
    int sum = 0;
    queue<int> q;
    // 入度为0的入队
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 入栈
        topS.push(u);
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i].v,
                w = Adj[u][i].w;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
            // 生成事件的最早开始事件
            if (ve[u] + w > ve[v]) {
                ve[v] = ve[u] + w;
            }
        }
        sum++;
    }
    return sum == n;
}

int criticalPath() {
    if (!topologySort()) {
        printf("当前图非有向无环图\n");
        return -1;
    }
    // 初始化vl[k]的值为关键路径长度(也可理解为事件的最迟开始时间)
    fill(vl, vl + n, ve[n - 1]);
    while (!topS.empty()) {
        int u = topS.top();
        topS.pop();
        // 生成vl[k]事件的最晚开始时间
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i].v,
                w = Adj[u][i].w;
            if (vl[v] - w < vl[u]) {
                vl[u] = vl[v] - w;
            }
        }
    }
    // 遍历关键路径的结点
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v, w = Adj[u][j].w;
            int e = ve[u],  // 活动u的最早开始时间
            l = vl[v] - w;    // 活动u的最迟开始时间
            // 显然，当e == l时，此点为关键路径
            if (e == l) {
                printf("%d -> %d\n", u, v);
            }
        }
    }
    return ve[n - 1];
}

void initPara() {
    n = 6;
    inDegree[0] = 0;
    inDegree[1] = 1;
    inDegree[2] = 1;
    inDegree[3] = 1;
    inDegree[4] = 2;
    inDegree[5] = 1;
    Adj[0].push_back(Node(1, 30));
    Adj[0].push_back(Node(3, 40));
    Adj[1].push_back(Node(2, 40));
    Adj[2].push_back(Node(4, 50));
    Adj[3].push_back(Node(4, 40));
    Adj[4].push_back(Node(5, 70));
}

int main() {
    initPara();
    int ans = criticalPath();
    printf("%d\n", ans);
}