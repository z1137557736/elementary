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

int ans[99],    // 存放每一行的叶子结点的和
n = 0;      // 存放最后一行的高度

void dfs(BTree T, int h) {
    if (T == nullptr) return;
    ans[h] += T->data;  // 累加层次相同的结点值之和
    if (n < h) n = h;   // 保持n为最后一行的高度
    dfs(T->lchild, h+1);
    dfs(T->rchild, h+1);
}

int main() {
    BTree T;
    buildTree(T);
    dfs(T, 0);
    cout << ans[n] << endl;
}