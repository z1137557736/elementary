#include <iostream>
#include <algorithm>
#include <cmath>

/**
 * 题意：本质上就是个最小生成树，只不过边权需要我们自己生成
 * 即取最小生成树中最大的那条边的边权
 */

using namespace std;

typedef pair<int, int> pt;

const int MAX_SIZE = 110;   // 最大顶点个数

struct Edge {
    int u, v;
    double w;
}edge[MAX_SIZE * (MAX_SIZE - 1)];

pt points[MAX_SIZE];  // 坐标

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int father[MAX_SIZE];
int n;   // 当前图的顶点数以及边数

int findFather(int x) {
    if (father[x] == x) return x;
    else return findFather(father[x]);
}

void kruskal(int m) {
    // 1. 自成连通分量
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
    sort(edge, edge + m, cmp);
    int sum = 0;    // 当前生成树的边数
    for (int i = 0; i < m; i++) {
        // 2. 查找根结点
        int fa = findFather(edge[i].u);
        int fb = findFather(edge[i].v);
        if (fa != fb) {
            // 3. 合并连通分量
            father[fb] = fa;
            sum++;
            if (sum == n - 1){
                printf("%.2f\n", sqrt(edge[i].w));
            }
        }
    }
}

double dis(pt a, pt b) {
    return pow((a.first - b.first), 2) + pow(a.second - b.second, 2);
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                edge[m].u = i; edge[m].v = j;
                edge[m].w = dis(points[i], points[j]);
                m++;
            }
        }
        kruskal(m);
    }
}