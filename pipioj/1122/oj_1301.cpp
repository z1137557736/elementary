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

void swapTree(BTree T) {
    if (T) {
        swapTree(T->lchild);
        swapTree(T->rchild);
        BTree tmp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = tmp;
    }
}

void printTree(BTree T) {
    if (T) {
        cout << T->data << ' ';
        printTree(T->lchild);
        printTree(T->rchild);
    }
}


int main() {
    BTree T;
    buildTree(T);
    swapTree(T);
    printTree(T);
    cout << endl;
    return 0;
}