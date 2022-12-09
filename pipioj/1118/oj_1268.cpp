#include <iostream>

using namespace std;

/**
* 分析
 * 1. 左子树的 先序序列 和 中序序列
 * 2. 右子树的 先序序列 和 中序序列
*/

typedef struct BNode {
    int data;
    BNode *lchild, *rchild;
} BNode, *BTree;

const int MAX_SIZE = 120;

int pre[MAX_SIZE], in[MAX_SIZE];    // 存放先序序列和中序序列

// preL与和preR为先序序列的区间范围，inL与inR为中序序列的区间范围
BTree createPreIn(int preL, int preR, int inL, int inR) {
    if (preL > preR) return nullptr;

    BTree T = new BNode;
    T->data = pre[preL];   // 先序序列的首元素总是为根结点

    int k = 0;  // k是划分中序序列化为左右子树的分界点
    while (k <= inR && in[k] != pre[preL]) k++;
    int leftnum = k - inL;  // 左子树结点个数
    // 左子树的先序与中序序列范围
    T->lchild = createPreIn(preL + 1, preL + leftnum, inL, k - 1);
    // 右子树的先序与中序序列范围
    T->rchild = createPreIn(preL + leftnum + 1, preR, k + 1, inR);

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
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    printTree(createPreIn(0, n - 1, 0, n - 1));
    return 0;
}
