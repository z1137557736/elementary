#include <iostream>
#include <vector>

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

vector<int> ve[2];  // 用于存放相应二叉树的先序序列

// 中序遍历生成先序序列
void inOrder(BTree T, int i) {
    if (T == nullptr) return;
    inOrder(T->lchild, i);
    ve[i].push_back(T->data);
    inOrder(T->rchild, i);
}

void merge() {
    int i = 0, j = 0;
    while (i < ve[0].size() && j < ve[1].size()) {
        if (ve[0][i] < ve[1][j]) cout << ve[0][i++] << ' ';
        else cout << ve[1][j++] << ' ';
    }
    while(i < ve[0].size())  cout << ve[0][i++] << ' ';
    while(j < ve[1].size())  cout << ve[1][j++] << ' ';
}

int main() {
    BTree TA, TB;
    buildTree(TA);
    buildTree(TB);
    inOrder(TA, 0);
    inOrder(TB, 1);
    merge();
    cout << endl;
    return 0;
}
