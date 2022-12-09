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

int ans = 0;

int getDepth(BTree T) {
    if (T == nullptr) return 0;
    return max(getDepth(T->lchild), getDepth(T->rchild)) + 1;
}

int dfs(BTree T) {
    if (T == nullptr) return -1;    // 非法数据
    if (T->lchild == nullptr && T->rchild == nullptr) return T->data;   // 返回最左边的值（一定是个叶子结点）
    int l = getDepth(T->lchild);
    int r = getDepth(T->rchild);
    if (l >= r) return dfs(T->lchild);  // 深度高者优先，左边优先
    else return dfs(T->rchild);
}

int main() {
    BTree T;
    buildTree(T);

    cout << dfs(T) << endl;
    return 0;
}