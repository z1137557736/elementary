#include <iostream>

/**
 * 题意：最大和树，基于二叉搜索树的中序序列，每个结点的值 = 当前值+后继值
 * 解题思路：右根左，逆中序遍历实现
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

int next_val = 0;   // 记录后继的值

void maxSumTree(BTree T) {
    if (T) {
        maxSumTree(T->rchild);
        T->data+=next_val;
        next_val = T->data; // 保持next_val为后继的值
        maxSumTree(T->lchild);
    }
}

void printTree(BTree T) {
    if (T) {
        cout << T->data << ' ';
        printTree(T->lchild);
        printTree(T->rchild);
    } else {
        cout << "-1 ";
    }
}

int main() {
    BTree T = nullptr;
    buildTree(T);
    maxSumTree(T);
    printTree(T);
    cout << endl;
    return 0;
}
