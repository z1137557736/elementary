#include <cstdio>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 二叉查找树的基本操作
 */

struct Node {
    int data, layer, count;
    Node *left, *right;
};

// 二叉查找树插入结点
void insert(Node *&node, int x) {
    if (node == nullptr) {
        node = new Node;
        node->data = x;
        node->count = 0;
        node->left = node->right = nullptr;
        return;
    }
    if (node->data > x) {
        insert(node->left, x);
    } else if (node->data < x) {
        insert(node->right, x);
    } else {
        printf("duplicate value : %d\n", x);
    }
}

// 由给定值创建二叉查找树
Node *create(int arr[], int n) {
    Node *node = nullptr;
    for (int i = 0; i < n; i++) {
        insert(node, arr[i]);
    }
    return node;
}

// 根据值来搜寻结点
Node *search(Node *node, int x) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data > x) {
        search(node->left, x);
    } else if (node->data < x) {
        search(node->right, x);
    } else {
        printf("%d\n", node->data);
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
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->data <= pre) {
            return false;
        }
        pre = root->data;
        return isValidBST(root->right);
    } else {
        return true;
    }
}

// 如果二叉树是二叉排序树，则中序遍历过程中一定是有序的
int predata = -0x7ffff; // 这里为前驱结点的值，假设为-∞
bool judgeBST(Node *T) {
    if (T == nullptr) return true;  // 空树无需判定，直接返回true
    bool l = judgeBST(T->left);   // 对左子树进行判定
    // 若左子树非二叉排序树 或 前驱结点的值大于当前结点值. 则判定为非二叉树
    if (!l || predata >= T->data) return false; // 返回false
    predata = T->data;    // 更新前驱结点的值
    return judgeBST(T->right);    // 进行去右子树进行判定
}

bool printx(Node *T, int x) {
    if (T) {
        printx(T->left, x);
        if (T->data >= x) printf("%d ", T->data);
        printx(T->right, x);
    }
}

// 非递归形式的后序遍历
/**
 * 1. 定义工作栈s, 工作指针p, 默认指向根结点
 * 2. 若当前p不为空，将p入栈并指向左孩子
 * 3. 若当前p指针为空，则将栈顶元素弹出并将p指向其右子树
 */
void postOrder(Node *T) {
    Node *p = T, *preNode = nullptr; // 定义工作指针和前驱结点
    stack<Node *> s;
    while (p || !s.empty()) {
        if (p) {    // 若当前p不为空，将p入栈并指向左孩子
            // cout << p -> data;  // 先序输出
            s.push(p);
            p = p->left;
        } else { // 若当前p指针为空，则将栈顶元素弹出并将p指向其右子树
            // 后序遍历
            p = s.top();
            // 借助辅助指针
            // case1: p的右孩子为空 || p的右孩子已经输出（即前驱结点为右子树）
            // case2: p的右孩子未被访问
            // case1 - 步骤
            // 1. 出栈并访问该结点
            // 2. 前驱结点的指针指向p
            // 3. p 指向空指针（标识当前子树已遍历完毕）
            // case2 - 步骤
            // 1. p 继续遍历其右子树
            if (p->right == nullptr || p->right == preNode) {
                s.pop();
                cout << ' ' << p->data;
                preNode = p;
                p = nullptr;
            } else {
                p = p->right;
            }
            /*p = s.top(); s.pop();
            cout << p -> data;  // 中序输出
            p = p -> right;*/
        }
    }
}

// 二叉树非递归的方式插入元素x, 重复插入时，count++
void insertX(Node *&T, int x) {
    Node *b = new Node; // 初始化数据
    b->data = x;
    b->count = 0;
    b->left = b->right = nullptr;
    if (T == nullptr) { // 空树直接赋值并返回
        T = b;
        return;
    }
    Node *p = T, *preNode;  // 定义一个工作指针 以及 指向上一次被访问的结点指针
    while (p) {
        if (p->data == x) { // 如果已存在x，count++，并直接返回
            p->count++;
            return;
        }
        preNode = p;
        if (p->data > x) p = p->left;   // x小于当前结点值，则往左子树查找
        else p = p->right;  // x大于当前结点值，则往右子树查找
    }
    if (preNode -> data > x) preNode -> left = b;   // x小于当前结点值，则作为preNode的左孩子
    else preNode -> right = b;  // x大于当前结点值，则作为preNode的右子树
}

/**
 * 求出指定结点在二叉树的层次
 */
int getLayer(Node *root, int x) {
    queue<Node *> q;
    root->layer = 1;
    q.push(root);
    while (!q.empty()) {
        Node *f = q.front();
        q.pop();
        if (f->data == x) {
            return f->layer;
        }
        if (f->left) {
            f->left->layer = f->layer + 1;
            q.push(f->left);
        }
        if (f->right) {
            f->right->layer = f->layer + 1;
            q.push(f->right);
        }
    }
}

// 后序遍历，自顶向上
int order(Node *root) {
    if (root == nullptr) return 0;
    int left = order(root->left);
    if (left == -1) return left;
    int right = order(root->right);
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
        work10(root->right, k);
        if (root->data >= k) printf("%d ", root->data);
        work10(root->left, k);
    }
}

int cnt = 1;

// 返回二叉排序树中第k个小的元素的指针
Node *work11(Node *root, int k) {
    if (root != nullptr) {
        work11(root->left, k);
        if (cnt == k) return root;
        cnt++;
        work11(root->right, k);
    }
}

int main() {
    int A[6] = {9, 5, 4, 7, 13, 17};
    Node *root = create(A, 6);

    insertX(root, 10);

    // search(root, 1);

    postOrder(root);

    cout << endl;

    // 判断是否为二叉搜索树
    printf("是否为二叉搜索树：%d\n", isValidBST(root));
    printf("是否为二叉搜索树：%d\n", judgeBST(root));

    printx(root, 2);

    // 求出指定结点在二叉树的层次
    printf("\n%d\n", getLayer(root, 3));

    // 从大到小输出二叉排序树中所有值不小于k的关键字
    // work10(root, 5);步骤

    // 返回二叉排序树中第k个小的元素的指针
    printf("%d\n", work11(root, 4)->data);
    return 0;
}