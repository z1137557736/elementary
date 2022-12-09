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

// 判断T的左子树是不是右子树的镜像树
bool isMirrorTree(BTree A, BTree B) {
    if (!A && !B) return true;  // 都为空，则为相同
    if (!A || !B) return false; // 非对称二叉树
    return A->data == B->data
           && isMirrorTree(A->rchild, B->lchild)
           && isMirrorTree(A->lchild, B->rchild);
}

int main() {
    BTree T;
    buildTree(T);
    if (isMirrorTree(T, T)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}