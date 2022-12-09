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

/**
 * 判断两个树是否同构的三个点
 * 1. 根结点是否相等
 * 2. T1与T2的左右子树是否同构
 * 3. T1的镜像与T2的左右子树是否同构
 */
bool isSameStructTree(BTree T1, BTree T2) {
    if (!T1 && !T2) return true;  // 都为空，则为同构

    if (!T1 || !T2) return false; // 一个为空，为非同构

    if (T1->data != T2->data) return false; // 根结点不同，非同构

    return (isSameStructTree(T1->lchild, T2->lchild) && isSameStructTree(T1->rchild, T2->rchild))
           || (isSameStructTree(T1->rchild,T2->lchild) && isSameStructTree(T1->lchild,T2->rchild));
}

int main() {
    BTree T1,T2;
    buildTree(T1);
    buildTree(T2);
    if (isSameStructTree(T1,T2)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}