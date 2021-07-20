#include <cstdio>
#include <queue>

using namespace std;

typedef int VType;
const int MAX_SIZE = 1000;

/**
 * （Breadth First Search）广度优先搜索
 * 邻接矩阵版 与 邻接表版
 */

/** 邻接矩阵版 遍历图 开始  **/

// 定义邻接矩阵 1 为有边 0 为0无边
VType G[MAX_SIZE][MAX_SIZE] = {};
// 顶点数
int n;
// 顶点是否入队
bool inq[MAX_SIZE] = {};
// 定义队列用于BFS
queue<int> q;

/**
 * 广度优先搜索遍历图
 * 采用BFS的思想去遍历图，遍历与顶点v所有可能邻接的(未入队)顶点
 * @param v 顶点标识
 */
void BFS(int v) {
    q.push(v);
    inq[v] = true;
    while (!q.empty()) {
        int f = q.front();
        printf("%d", f);
        q.pop();
        for (int i = 0; i < n; i++) {
            if (G[f][i] == 1 && !inq[i]) {
                q.push(i);
                inq[i] = true;
            }
        }
    }
}

// 遍历图(因为该图不一定为连通图，因此要保证每个顶点都有机会被访问到)
void traverseGraph() {
    for (int i = 0; i < n; i++) {
        // 当且仅当，当前顶点未入队
        if (!inq[i]) {
            BFS(i);
        }
    }
}

/** 邻接矩阵版 遍历图 结束  **/

/** 邻接表版 遍历图 开始  **/

struct ArcNode {
    VType adjVex; // 邻接顶点
    ArcNode *next;
};

struct VexNode {
    VType data; // 当前顶点
    ArcNode *first;
} vexNode[MAX_SIZE];

// 邻接表式图的广度优先搜索
void BFS2(int v) {
    printf("%d", v);
    q.push(v);
    inq[v] = true;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        ArcNode *arc = vexNode[f].first;
        while (arc != nullptr) {
            if (!inq[arc -> adjVex]) {
                q.push(arc -> adjVex);
                inq[arc -> adjVex] = true;
            }
            arc = arc -> next;
        }
    }
}

// 邻接表式图的遍历
void traverseGraph2() {
    for (int i = 0; i < n; i++) {
        if (!inq[i]) {
            BFS2(i);
        }
    }
}

/** 邻接表版 遍历图 结束  **/

int main() {
    // 初始化邻接矩阵的数据
    n = 2;
    G[0][1] = 1;
    G[1][0] = 1;
    traverseGraph();

    return 0;
}