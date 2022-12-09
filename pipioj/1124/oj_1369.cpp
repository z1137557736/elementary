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

int maxDepth(BTree T) {
    if (T == nullptr) return 0;
    return max(maxDepth(T->lchild), maxDepth(T->rchild)) + 1;
}

int main() {
    BTree T;
    buildTree(T);
    cout << maxDepth(T) << endl;
    return 0;
}

