#include <cstdio>

// 只考虑中序遍历的线索树

struct ThreadNode {
    char data;
    ThreadNode *lchild, *rchild;
    int ltag;   // 0 左孩子 1 前驱
    int rtag;   // 0 右孩子 1 后继
};

// ABC##D##EF### 先序的方式创建二叉树
void createNode(ThreadNode *&node) {
    char c;
    scanf("%c", &c);
    // 退出符
    if (c == '#') {
        // 令指针为空指针
        node = NULL;
    } else {
        node = new ThreadNode;
        node -> data = c;
        node -> ltag = node -> rtag = 0;
        createNode(node -> lchild);
        createNode(node -> rchild);
    }
}

/**
 * 递归实现将二叉树中序线索化
 * @param p 指向当前访问结点
 * @param pre 重点，要从中序序列的角度来看，始终指向上一个被访问的指针对象
 */
void inThreading(ThreadNode *&p, ThreadNode *&pre) {
    if (p != NULL) {
        inThreading(p -> lchild, pre);
        if (p -> lchild == NULL) {    // 当前结点的左子树为空，建立前驱线索
            p -> lchild = pre;
            p -> ltag = 1;
        }
        if (pre && pre -> rchild == NULL) {  // 前驱结点的右子树为空，建立后继线索
            pre -> rchild = p;
            pre -> rtag = 1;
        }
        pre = p;
        inThreading(p -> rchild, pre);
    }
}

ThreadNode* firstNode(ThreadNode *p) {   // 定位当前结点的最左下结点
    while (p && p -> ltag == 0) p = p -> lchild;  // 当前结点的左子树存在，继续向左下遍历
    return p;    // 返回最左下结点
}

ThreadNode* findNext(ThreadNode *p) {   // 返回当前结点的后继结点
    if (p -> rtag == 0) return firstNode(p -> rchild);  // 若当前结点存在右子树，其后继结点为其右子树的最左下结点
    return p -> rchild;  // 若当前结点无右子树，返回后继线索
}


void inThreadOrder(ThreadNode *p) {
    p = firstNode(p);
    while (p) {
        printf("%c", p -> data);
        p = findNext(p);
    }
}

void preOrder(ThreadNode *node) {
    if (node != NULL) {
        printf("%c", node -> data);
        preOrder(node -> lchild);
        preOrder(node -> rchild);
    }
}

void inOrder(ThreadNode *node) {
    if (node != NULL) {
        inOrder(node -> lchild);
        printf("%c", node -> data);
        inOrder(node -> rchild);
    }
}


int main() {
    ThreadNode *node = NULL;
    ThreadNode *pre = NULL;
    // 创建二叉树
    createNode(node);

    /*// 先序遍历
    preOrder(node);
    printf("\n");

    // 中序遍历二叉树
    inOrder(node);
    printf("\n");*/

    // 线索化二叉树
    inThreading(node, pre);

    // 中序遍历线索二叉树
    inThreadOrder(node);
    return 0;
}
