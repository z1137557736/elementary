#include <iostream>

using namespace std;

typedef struct BNode {
    int data;
    BNode *lchild, *rchild;
} *BTree;

void createTree(BTree &T) {
    int d;
    cin >> d;
    if (d != -1) {
        T = new BNode;
        T -> data = d;
        createTree(T->lchild);
        createTree(T->rchild);
    } else {
        T = nullptr;
    }
}

// 判断两棵树是否相等
bool isResemble(BTree A, BTree B) {
    if (A == nullptr && B == nullptr) return true;
    return A && B
           && A -> data == B -> data
           && isResemble(A->lchild, B->lchild)
           && isResemble(A->rchild, B->rchild);
}

bool isSubTree(BTree root, BTree subRoot) {
    if (root == nullptr) return false;  // subRoot非root子树

    //判断两棵树是否相等
    if (isResemble(root, subRoot)) {
        return true;
    }

    return isSubTree(root -> lchild, subRoot) || isSubTree(root->rchild, subRoot);
}

int main() {
    BTree root, subRoot;
    createTree(root); createTree(subRoot);
    if (isSubTree(root, subRoot)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}