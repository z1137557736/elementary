#include <iostream>

/**
 * 题意：删除给定值的叶子结点
 * 两个重点 - 1. 后序定位叶子结点 2. 删除叶子结点
 */

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

BTree delLeafNode(BTree T, int target) {
    if (T == nullptr) return nullptr;

    T->lchild = delLeafNode(T->lchild, target); // 更新左孩子
    T->rchild = delLeafNode(T->rchild, target); // 更新右孩子

    if (T->data == target && T->lchild == nullptr && T->rchild == nullptr) {
        return nullptr; // 删除给定的叶子结点
    }
    return T;
}

void printTree(BTree T) {
    if (T == nullptr) return;
    cout << T->data << ' ';
    printTree(T->lchild);
    printTree(T->rchild);
}

int main() {
    int target;
    BTree T;
    buildTree(T);
    cin >> target;
    printTree(delLeafNode(T, target));
    cout << endl;
    return 0;
}