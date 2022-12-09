#include <iostream>

/**
 * 题意：在递归过程中存储每个结点的祖先结点，若命中待查询结点，则输出其祖先结点
 * 解题思路：右根左，逆中序遍历实现
 */

using namespace std;

typedef struct BNode{
    int data;
    BNode *lchild, *rchild;
} *BTree;

const int max_size = 1000;
int ancestors[max_size];
int flag = 0;   // 标识是否找到待查询结点

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

void findAncestor(BTree T, int x, int k) { // x为待查询的结点，k为祖先个数-初始为0
    if (!T) return; // 空树直接return
    if (T->data == x) {
        flag = 1;   // 标识已找到该结点
        if (k == 0) {   // 无祖先结点
            cout << "No Ancestor!" << endl;
        } else {
            for (int i = 0; i < k; i++) {
                cout << ancestors[i] << ' ';
            }
            cout << endl;
        }
        return; // 退出当前递归
    }
    ancestors[k++] = T->data; // 记录祖先
    findAncestor(T->lchild, x, k);
    findAncestor(T->rchild, x, k);
}

int main() {
    BTree T;
    buildTree(T);
    int x;
    cin >> x;
    findAncestor(T, x, 0);
    if (flag == 0) cout << "No Node!" << endl;  // 没找到该结点
    return 0;
}