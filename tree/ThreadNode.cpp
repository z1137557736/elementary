#include <cstdio>

// 只考虑中序遍历的线索树

struct ThreadNode {
    char data;
    ThreadNode *left, *right;
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
        createNode(node -> left);
        createNode(node -> right);
    }
}

/**
 * 递归实现将二叉树中序线索化
 *
 * 1. 先进行中序遍历，从中序序列上的角度上的，定义pre结点用于记录: 刚刚被访问的结点, 并反复执行第2、3、4步
 * 2. 若 p -> left == null, 则 p -> left = pre; p -> ltag = 1
 * 3. 若 pre != null && pre -> right == null, 则 pre -> right = p; pre -> rtag = 1
 * 4. 用于记录刚刚所访问的结点 pre = p
 * @param p 指向当前访问结点
 * @param pre 重点，要从中序序列的角度来看，始终指向上一个被访问的指针对象
 */
void inThreading(ThreadNode *&p, ThreadNode *&pre) {
    if (p != NULL) {
        inThreading(p -> left, pre);
        if (p -> left == NULL) {    // 若当前结点的左孩子为空
            p -> left = pre;    // 将其左孩子指向前驱结点
            p -> ltag = 1;      // 并标记左孩子标记为前驱结点
        }
        if (pre != NULL && pre -> right == NULL) {  // 若pre的右孩子为空
            pre -> right = p;   // 将pre的右孩子指向当前结点
            pre -> rtag = 1;    // 将当前右孩子标记为后继结点
        }
        pre = p;
        inThreading(p -> right, pre);
    }
}

// 寻找中序序列的首结点
ThreadNode* firstNode(ThreadNode *node) {
    while (node -> ltag == 0) node = node -> left;
    return node;
}

//
/**
 * 寻找后继结点
 * 1. 若p -> right == null, 则已到达链表的最后一个结点，返回null
 * 2. 若p -> rtag == 1, 直接返回 p -> right
 * 3. 若p -> rtag == 0, p的右孩子非其后继结点，并通过p的右孩子去寻找p的后继结点(在中序序列中，p的右孩子的最左孩子为p的后继结点)
 */
// 如果为 node -> right 为线索值
ThreadNode* findNext(ThreadNode *p) {
    // 后继结点为空，直接返回（此时已到达尾结点）
    if (p -> right == NULL) return p -> right;

    if (p -> rtag == 1) return p -> right;
    else return firstNode(p -> right);
}


void inThreadOrder(ThreadNode *node) {
    ThreadNode *next = firstNode(node);
    while (next != NULL) {
        printf("%c", next -> data);
        next = findNext(next);
    }
}

void preOrder(ThreadNode *node) {
    if (node != NULL) {
        printf("%c", node -> data);
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void inOrder(ThreadNode *node) {
    if (node != NULL) {
        inOrder(node -> left);
        printf("%c", node -> data);
        inOrder(node -> right);
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
