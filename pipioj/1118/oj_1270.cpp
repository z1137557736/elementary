#include <iostream>

using namespace std;

const int MAX_SIZE = 120;

int pre_order[MAX_SIZE];

typedef struct BNode {
    int data;
    BNode *lchild, *rchild;
} BNode, *BTree;

// 插入元素
void insert(BTree &T, int x) {
    if (T == nullptr) {
        T = new BNode;
        T->data = x;
        T->lchild = nullptr;
        T->rchild = nullptr;
    } else {
        if (T->data > x) insert(T->lchild, x);
        else if (T->data < x) insert(T->rchild, x);
    }
}

// 创建二叉搜索树
BTree createBST(int n) {
    BTree T = nullptr;
    for (int i = 0; i < n; i++) {
        insert(T, pre_order[i]);
    }
    return T;
}

void printTree(BTree T) {
    if (T) {
        printTree(T->lchild);
        printTree(T->rchild);
        cout << T->data << ' ';
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre_order[i];
    }
    printTree(createBST(n));
    return 0;
}