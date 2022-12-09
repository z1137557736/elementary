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

int getDepth(BTree T) {
    if (T == nullptr) return 0;
    return max(getDepth(T->lchild), getDepth(T->rchild)) + 1;
}

bool isBalanced(BTree T) {
    if (T == nullptr) return true;
    int l = getDepth(T->lchild);
    int r = getDepth(T->rchild);
    return abs(l - r) <= 1 && isBalanced(T->lchild) && isBalanced(T->rchild);
}

int main() {
    BTree T;
    buildTree(T);
    if (isBalanced(T)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}