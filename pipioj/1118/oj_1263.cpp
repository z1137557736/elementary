#include <iostream>
#include <algorithm>

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

int ans = 0;    // 结点与其祖先之间的最大差值, 若树为空，返回0
// 所谓的结点与祖先的最大差值，就结点分别与祖先的最大值和最小值的差值
// 定义maxv为祖先的最大值，minv为祖先的最小值

void maxAncestorDiff(BTree T, int maxv, int minv) {
    if (T == nullptr) return;

    ans = max(ans, max(abs(maxv - T->data), abs(minv - T->data)));

    maxv = max(maxv, T -> data);    // 保持maxv为祖先的最大值
    minv = min(minv, T -> data);    // 保持minv为祖先的最小值

    maxAncestorDiff(T -> lchild, maxv, minv);

    maxAncestorDiff(T -> rchild, maxv, minv);
}

int main() {
    BTree T;
    createTree(T);
    if (T != nullptr) {
        maxAncestorDiff(T, T -> data, T -> data);
    }
    cout << ans << endl;

    return 0;
}