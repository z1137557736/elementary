#include <iostream>

using namespace std;

typedef struct BNode {
    int data;
    BNode *lchild, *rchild;
} BNode, *BTree;

const int MAX_SIZE = 120;

int in_order[MAX_SIZE], post_order[MAX_SIZE];  // 定义中序序列和后序序列

// 核心 - 确定左右子树所对应的中序和后序序列
BTree createInPost(int inL, int inR, int postL, int postR) {
    if (inL > inR) return nullptr;

    BTree T = new BNode;
    T -> data = post_order[postR];

    int k = 0;  // 定位中序序列（树的）根结点
    while (k <= inR && in_order[k] != post_order[postR]) k++;
    int leftnum = k - inL;  // 左子树的结点个数

    T -> lchild = createInPost(inL, k - 1, postL, postL + leftnum - 1);
    T -> rchild = createInPost(k + 1, inR, postL + leftnum, postR - 1);
    return T;
}

void printTree(BTree T) {
    if (T) {
        cout << T -> data << ' ';
        printTree(T -> lchild);
        printTree(T -> rchild);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in_order[i];
    for (int i = 0; i < n; i++) cin >> post_order[i];
    printTree(createInPost(0, n - 1, 0, n - 1));
    return 0;
}