#include <cstdio>
#include <queue>

using namespace std;

/**
 * 实现二叉树的四种遍历方式
 * 如 前序遍历，中序遍历，后序遍历， 其中 '前' '中' '后' 分别指的是根结点被访问的顺序
 * 递归实现前中后序遍历 以及 基于队列实现层序遍历
 */

struct Node {
    int data;
    Node *left, *right; // 左右子结点
};

// 前序遍历
void preOrder(Node *node) {
    if (node != NULL) {
        printf("%d", node -> data);
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

// 中序遍历
void inOrder(Node *node) {
    if (node != NULL) {
        inOrder(node -> left);
        printf("%d", node -> data);
        inOrder(node -> right);
    }
}

// 后序遍历
void postOrder(Node *node) {
    if (node != NULL) {
        postOrder(node -> left);
        postOrder(node -> right);
        printf("%d", node -> data);
    }
}

// 层序遍历(基于BFS 广度优先搜索 所实现)

/**
 * 1. 定义队列q, 并将根结点入队，并反复执行第2、3、4步，直到队列为空
 * 2. 访问队首结点并将其出队
 * 3. 若队首结点的左子结点不为空，则将左子结点入队
 * 4. 若队首结点的右子结点不为空，则将右子结点入队
 */
void layerOrder(Node *node) {
    // 定义队列
    queue<Node*> q;
    if (node != NULL) {    // 若根结点不为空
        q.push(node);   // 将根结点入队
        while (!q.empty()) {    // 若队列不为空
            Node* top = q.front();  // 获取队首元素
            q.pop();    // 队首元素出队并输出其值
            printf("%d", top -> data);
            if (top -> left) {  // 若其左孩子不为空，则入队
                q.push(top -> left);
            }
            if (top -> right) { // 若其右孩子不为空，则入队
                q.push(top -> right);
            }
        }
    }
}