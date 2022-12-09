#include <iostream>

/**
 * 题意：找兄弟
 */

using namespace std;

typedef struct BNode{
    int data;
    BNode *lchild, *rchild;
} *BTree;

int flag = 0;   // 0标识其他关系，1标识兄弟
int i = -1, j = -1;   // x的层次和y的层次，若i和j相同，则标识为表亲

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

void isGeneration(BTree T, int x, int y, int layer) {   // layer记录层次
    if (!T) return;
    if (T -> lchild && T->rchild && ((T->lchild->data == x && T->rchild->data == y)
                                     || (T->lchild->data == y && T->rchild->data == x))) { // x与y为兄弟结点
        flag = 1;   // 标记为同辈关系
        return;
    }
    if (T->data == x) {
        i = layer;
    }
    if (T->data == y) {
        j = layer;
    }
    isGeneration(T->lchild, x, y, layer + 1);
    isGeneration(T->rchild, x, y, layer + 1);
}

int main() {
    BTree T;
    buildTree(T);
    int x, y;
    cin >> x >> y;
    isGeneration(T, x, y, 0);
    if (flag == 1) cout << "brother" << endl;
    else if (i == j && i != 0) cout << "cousin" << endl;    // 两结点不是
    else cout << "other relathionship" << endl;
    return 0;
}