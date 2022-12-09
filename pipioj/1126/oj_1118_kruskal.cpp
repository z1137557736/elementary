#include <iostream>

using namespace std;

const int MAX_SIZE = 110;   // 最大顶点个数

/**
 * <h2>城城通</h2>
 * 分析：本质上是一个最小生成树的问题，对于已修建的路，只需令其cost为0即可。
*/
struct Edge{
    int u, v, w;    // 两顶点，一边权
} edge[MAX_SIZE * (MAX_SIZE - 1) / 2];   // 边集

int father[MAX_SIZE];   // 定义并查集

bool cmp(Edge a, Edge b) {
    return a.w < b.w;   // 从小到大
}

int findFather(int x) {
    if (father[x] == x) return x;
    else {
        int f = findFather(father[x]);
        father[x] = f;  // 压缩路径
        return f;
    }
}

int kruskal(int n, int m) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;  // 自成连通分量
    }
    sort(edge, edge + m, cmp);
    int sum = 0,    // 记录生成树边的个数
        ans = 0;    // 最小生成树的边权
    for (int i = 0; i < m; i++) {
        // 查找
        int fa = findFather(edge[i].u);
        int fb = findFather(edge[i].v);
        if (fa != fb) {
            father[fa] = fb;    // 合并连通分量
            sum++;
            ans += edge[i].w;
            if (sum == n - 1) break;   // 最小生成树已构建完毕, 退出循环
        }
    }
    return ans;
}

int main() {
    int n, m;
    while (cin >> n) {
        if (n == 0) return 0;
        m = n * (n - 1) / 2;
        for (int i = 0; i < m; i++) {
            int t;
            cin >> edge[i].u >> edge[i].v >> edge[i].w >> t;
            if (t == 1) edge[i].w = 0;  // 已修建的通道，成本为0
        }
        cout << kruskal(n, m) << endl;
    }
}

