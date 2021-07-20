#include <cstdio>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * 二叉查找树的基本操作
 */

struct Node {
    int data, layer;
    Node *left, *right;
};

// 二叉查找树插入结点
void insert(Node *&node, int x) {
    if (node == nullptr) {
        node = new Node;
        node -> data = x;
        node -> left = node -> right = nullptr;
        return;
    }
    if (node -> data > x) {
        insert(node -> left, x);
    } else if (node -> data < x) {
        insert(node -> right, x);
    } else {
        printf("duplicate value : %d\n", x);
    }
}

// 由给定值创建二叉查找树
Node* create(int arr[], int n) {
    Node *node = nullptr;
    for (int i = 0; i < n; i++) {
        insert(node, arr[i]);
    }
    return node;
}

// 根据值来搜寻结点
Node* search(Node *node, int x) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node -> data > x) {
        search(node -> left, x);
    } else if (node -> data < x) {
        search(node -> right, x);
    } else {
        printf("%d\n", node -> data);
        return node;
    }
}

long long pre = LONG_LONG_MIN;

/**
 * 判断二叉树是否为二叉搜索树
 * 以中序遍历的思想进行判断
 * 1. 定义pre，并将其初始化为最小值LONG_LONG_MIN, 构造方法isValidBST();
 * 2. 进行递归遍历，反复执行以下步骤
 * 3. 若当前结点root为null, 则返回true
 * 4. 若当前结点不为空, 执行isValidBST(root -> left), 为false则直接返回false, 为true时继续往下执行
 * 5. 若pre >= root -> data, 直接返回false；并返回isValidBST(root -> right)
 */
bool isValidBST(Node *root) {
    if (root != nullptr) {
        if (!isValidBST(root -> left)) {
            return false;
        }
        if (root -> data <= pre) {
            return false;
        }
        pre = root -> data;
        return isValidBST(root -> right);
    } else {
        return true;
    }
}

/**
 * 求出指定结点在二叉树的层次
 */
int getLayer(Node *root, int x) {
    queue<Node*> q;
    root -> layer = 1;
    q.push(root);
    while (!q.empty()) {
        Node* f = q.front();
        q.pop();
        if (f -> data == x) {
            return f -> layer;
        }
        if (f -> left) {
            f -> left -> layer = f -> layer + 1;
            q.push(f -> left);
        }
        if (f -> right) {
            f -> right -> layer = f -> layer + 1;
            q.push(f -> right);
        }
    }
}

// 后序遍历，自顶向上
int order(Node *root) {
    if (root == nullptr) return 0;
    int left = order(root -> left);
    if (left == -1) return left;
    int right = order(root -> right);
    if (right == -1) return right;
    return abs(left - right) < 2 ? max(left, right) + 1 : -1;
}

// 判断二叉树是否为平衡二叉树
bool isBalanced(Node *root) {
    return order(root) != -1;
}

// 从大到小输出二叉排序树中所有值不小于k的关键字
void work10(Node *root, int k) {
    if (root != nullptr) {
        work10(root -> right, k);
        if (root -> data >= k) printf("%d ", root -> data);
        work10(root -> left, k);
    }
}

int cnt = 1;
// 返回二叉排序树中第k个小的元素的指针
Node* work11(Node *root, int k) {
    if (root != nullptr) {
        work11(root -> left, k);
        if (cnt == k) return root;
        cnt++;
        work11(root -> right, k);
    }
}

int main() {
    int A[6] = {4, 2, 1, 3, 5, 6};
    Node *root = create(A, 6);

    // search(root, 1);

    // 判断是否为二叉搜索树
    // printf("%d\n", isValidBST(root));

    // 求出指定结点在二叉树的层次
    printf("%d\n", getLayer(root, 3));

    // 从大到小输出二叉排序树中所有值不小于k的关键字
    // work10(root, 5);步骤

    // 返回二叉排序树中第k个小的元素的指针
    printf("%d\n", work11(root, 4) -> data);
    return 0;
}