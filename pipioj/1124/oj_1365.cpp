#include <iostream>

using namespace std;

typedef struct BNode{
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

void sumTree(BTree T, int fa, int gfa) {
    if (T == nullptr) return;

    if (gfa % 2 == 0) ans += T->data;   // 祖父结点是否为偶数

    sumTree(T->lchild, T->data, fa);
    sumTree(T->rchild, T->data, fa);
}

int main() {
    BTree T;
    buildTree(T);
    sumTree(T, -1, -1);
    cout << ans << endl;
    return 0;
}