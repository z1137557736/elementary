#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 平衡二叉树的建树、查询、插入(重点)
 *
 * 以及对应的三个方法
 * 1. 获取树的高度
 * 2. 获取当前结点的平衡因子
 * 3. 更新树的高度
 */

struct Node {
    int data, height;
    Node *left, *right;
};

int getHeight(Node *root) {
    if (root == nullptr) return 0;
    return root -> height;
}

// 获取平衡因子 当前根结点 左子树的高度 - 右子树的高度
int getBalancedFactor(Node *root) {
    return getHeight(root -> left) - getHeight(root -> right);
}

// 更新树的高度 当前结点 取左子树与右子树中的高度较大者并加1
void updateHeight(Node *root) {
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

/**
 * 左旋，如下图
 *       A                    C
 *     /  \      左旋后      /   \
 *    B    C     ---->     A     E
 *       /   \           /  \
 *      D     E         B    D
 */
void L(Node *&root) {
    Node *temp = root -> right;
    root -> right = temp -> left;
    temp -> left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

// 右旋与左转互逆
void R(Node *&root) {
    Node *temp = root -> left;
    root -> left = temp -> right;
    temp -> right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
/**
 * 平衡二叉树有关的四种树型的插入
 * 若当前结点root的平衡因子为2, 则有以下两种树形
 * 记 int factor = getBalancedFactor(root -> lchild)
 * 1. 当 factor == 1时, 则为LL树形, 右旋root结点
 * 2. 当 factor == -1时, 则为LR树形, 先左旋root -> lchild(可调整为LL树形)，再右旋root结点
 * 若root的平衡因子为-2, 则有以下两种树形
 * 记 int factor = getBalancedFactor(root -> rchild)
 * 1. 当 factor == -1时, 则为RR树形，左旋root结点
 * 2. 当 factor == 1时, 则为RL树形, 先右旋root -> right结点(调整为RR树形), 再左旋root结点
 */
void insert(Node *&root, int x) {
    if (root == nullptr) {
        root = new Node;
        root -> data = x;
        root -> height = 1;
        root -> left = root -> right = nullptr;
        return;
    }
    if (root -> data == x) {
        printf("duplicated value %d", x);
        return;
    } else if (x < root -> data) {
        insert(root -> left, x);
        updateHeight(root);
        // 则需要对树的结构需要调整
        if(getBalancedFactor(root) == 2) {
            int factor = getBalancedFactor(root -> left);
            if (factor == 1) {
                // LL树形
                R(root);
            } else if (factor == -1) {
                // LR树形
                L(root -> left);
                R(root);
            }
        }
    } else {
        insert(root -> right, x);
        updateHeight(root);
        if (getBalancedFactor(root) == -2) {
            int factor = getBalancedFactor(root -> right);
            if (factor == -1) {
                // RR树形
                L(root);
            } else if (factor == 1) {
                // RL树形
                R(root -> right);
                L(root);
            }
        }
    }
}

Node* create(int arr[], int n) {
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        insert(root, arr[i]);
    }
    return root;
}

Node* search(Node *root, int x) {
    if (root == nullptr) {
        return NULL;
    }
    if (x < root -> data) {
        search(root -> left, x);
    } else if (x > root -> data) {
        search(root -> right, x);
    } else {
        printf("%d", root -> data);
        return root;
    }
}

void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

int main() {
    int A[6] = {1, 2, 3, 4, 5, 6};
    Node *root = create(A, 6);
    // search(root, 1);
    inOrder(root);
    return 0;
}