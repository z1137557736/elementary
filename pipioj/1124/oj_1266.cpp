#include <iostream>
#include <algorithm>

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

// 暴力枚举每个树的两个最远结点的距离

int depth(BTree T) {
    if (T == nullptr) return 0;
    return max(depth(T->lchild) + 1, depth(T->rchild) + 1);
}

int ans = 0;

void maxDis(BTree T) {
    if (T == nullptr) return;

    int l = depth(T->lchild), r = depth(T->rchild);
    ans = max(l + r, ans);  // 保持ans为两结点最大距离

    maxDis(T->lchild);
    maxDis(T->rchild);
}


int main() {
    BTree T;
    buildTree(T);

    maxDis(T);
    cout << ans << endl;
    return 0;
}