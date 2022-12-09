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
        createTree(T -> lchild);
        createTree(T -> rchild);
    } else {
        T = nullptr;
    }
}

int pre = -0x7fffffff;  // 记录中序序列中前驱的值，默认为负无穷

bool isBST(BTree T) {
    if (T == nullptr) return true;
    bool flag = isBST(T -> lchild);
    // 中序序列严格单调增
    if (!flag || pre >= T -> data) return false;    // 若左子树非BST 或 前驱结点大于当前结点 判定都为非BST
    pre = T -> data;            // 保持pre为前驱结点
    return isBST(T -> rchild);  // 直接判定右子树
}

int main() {
    BTree T;
    createTree(T);

    if (isBST(T)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}