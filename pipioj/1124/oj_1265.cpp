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

BTree lowestCommonAncestor(BTree T, int x, int y) {
    if (!T) return nullptr;
    if (T->data == x || T->data == y) return T; // 定位到待查询结点，直接返回当前结点
    BTree left = lowestCommonAncestor(T->lchild, x, y);
    BTree right = lowestCommonAncestor(T->rchild, x, y);
    if (left == nullptr && right == nullptr) return nullptr;    // 左右孩子都为空，表明当前结点下无待查询结点
    if (left && right) return T;    // 若左右子树都存在，当前结点即为LCA
    else if (!left) return right;   // 返回非空的右孩子或左孩子
    else return left;
}

int main() {
    BTree T;
    int x, y;
    buildTree(T);
    cin >> x >> y;
    cout << lowestCommonAncestor(T, x, y)->data << endl;

    return 0;
}