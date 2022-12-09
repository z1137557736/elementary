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

void dfs(BTree T, int sum) {
    if (T == nullptr) return;
    sum += T->data;
    dfs(T->lchild, sum * 10);
    dfs(T->rchild, sum * 10);
    if (T->lchild == nullptr && T->rchild == nullptr) {
        ans += sum;
    }
}

int main() {
    BTree T;
    buildTree(T);
    dfs(T, 0);
    cout << ans << endl;
    return 0;
}