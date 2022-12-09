#include <iostream>

using namespace std;

typedef struct BNode {
    int data;
    BNode *lchild, *rchild;
} *BTree;

void buildTree(BTree &T) {
    int d;
    cin >> d;
    if (d != -1) {
        T = new BNode;
        T->data = d;
        buildTree(T->lchild);
        buildTree(T->rchild);
    } else {
        T = nullptr;
    }
}

int ans[99] = {0},  // 存储每一行的最大值，初始值为0, n
n = 0;          // 存储最大行数

void dfs(BTree T, int h) {
    if (T == nullptr) return;
    if (T->data > ans[h]) {
        ans[h] = T->data; // 大于则更新，保持ans[h]为每行的最大值
    }
    if (n < h) {
        n = h;  // 保持n为最大行数
    }
    dfs(T->lchild, h + 1);
    dfs(T->rchild, h + 1);
}

int main() {
    BTree T;
    buildTree(T);
    dfs(T, 0);
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}