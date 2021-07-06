#include <cstdio>

/**
 *  树的孩子兄弟表示法
 */

struct Node {
    char data;
    // 左孩子 右兄弟
    Node *nextSibling;
    Node *firstChild;
};

Node* newNode(char data) {
    Node *node = new Node;
    node -> data = data;
    node -> firstChild = NULL;
    node -> nextSibling = NULL;
    return node;
}

/**
 * 求树的叶子结点树
 * 若当前结点的firstChild为空(即为叶子结点)，并返回1
 * 反之，返回0
 */
int work5(Node *root) {
    // 递归边界
    if (root == nullptr) {
        return 0;
    }
    int ans = 0;
    if (root -> firstChild == nullptr) {
        ans = 1;
    }
    return ans + work5(root -> firstChild) + work5(root -> nextSibling);
}

/**
 * work6
 * 递归求树的深度
 * 若当前结点为空，则返回0
 */
int treeHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root -> firstChild == NULL) {
        return 1 + treeHeight(root -> nextSibling);
    } else {
        return treeHeight(root -> firstChild) + treeHeight(root -> nextSibling);
    }
}

int main() {
    Node *root = newNode('A');
    root -> firstChild = newNode('B');
    root -> nextSibling = newNode('C');
    root -> nextSibling -> firstChild = newNode('F');
//    root -> nextSibling -> nextSibling = newNode('D');

    printf("叶子结点树：%d\n", work5(root));

    printf("树的高度：%d\n", treeHeight(root));

    return 0;
}