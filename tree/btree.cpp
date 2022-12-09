#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 使用搜索引擎、画图、把变量打印出来看一下，可以解决 99% 以上的问题

struct Node {
    char data;
    int layer;  // 层次
    Node *left, *right;
};

char pre[6] = {'1', '2', '3', '4', '5', '6'};
char in[6] = {'3', '2', '4', '1', '6', '5'};
char post[5] = {'D', 'E', 'B', 'C', 'A'};

// 基于中序与后序序列构建二叉树
Node* createInPost(int inL, int inR, int postL, int postR) {
    if (inL > inR) {
        return NULL;
    }
    Node *root = new Node;
    root -> data = post[postR];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root -> left = createInPost(inL, k - 1, postL, postL + numLeft - 1);
    root -> right = createInPost(k + 1, inR, postL + numLeft, postR - 1);
    return root;
}

/**
 * Note: 中序序列可以与前序、后序、层序序列构建一棵二叉树；而前序、后序、层序三者合在都无法确定一棵树，###其核心原因就是无法区分左右子树###
 *
 * 基于先序序列与中序序列建立二叉树
 *
 * 1. 定义先序序列pre，其区间长度为[preL, preR]; 中序序列in, 其区间长度为[inL, inR]
 * 2. 并进行递归执行以下几步
 * 3. 若 preL > preR, 则 return null; // 递归边界
 * 4. 创建根结点root, 并令 root -> data = pre[preL]    // 先序序列的第一个结点为当前二叉树的根结点
 * 5. 遍历in的区间[inL, inR]，并寻找in[k] == pre[preL], 并取得k  // k可将中序序列分为两个区间; 左子树的区间[inL, k - 1], 右子树区间为[k + 1, inR]
 * 6. 以分治法的思想，去寻找当前根结点的左右孩子
 *    int numLeft = k - inL;    // 左子树结点的个数
 *    root -> lchild = create(preL + 1, pre + numLeft, inL, k - 1);
 *    root -> rchild = create(preL + numLeft + 1, preR, k + 1, inR);
 * 7. 最后返回 root根结点
 */
Node* createPreIn(int preL, int preR, int inL, int inR) {
    cout << "preL: " << preL << " preR: " << preR << " inL: " << inL << " inR: " << inR << endl;
    // 递归边界
    if (preL > preR) {
        return NULL;
    }
    Node *root = new Node;
    root -> data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    // 先序序列左子树的个数
    int numLeft = k - inL;
    // 左子树
    root -> left = createPreIn(preL + 1, preL + numLeft, inL, k - 1);
    // 右子树
    root -> right = createPreIn(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

// 先序序列建二叉树
void createNode(Node *&p) {
    char c;
    scanf("%c", &c);
    if (c != '#') {
        p = new Node;
        p -> data = c;
        createNode(p -> left);
        createNode(p -> right);
    } else {
        p = NULL;
    }
}

void visit(Node *node) {
    printf("%c ", node -> data);
}

/**
 * 非递归实现先序遍历
 *
 * 1. 定义栈来实现非递归先序遍历，并令p = node
 * 2. 若 p != null || !s.empty()，进行第三、四步的反复执行
 * 3. if (p != null) visit(p); s.push(p); p = p -> lchild;  // 先访问当前结点，再压左孩子入栈
 * 4. else p = s.top(); s.pop();    // 出栈并访问
 *    p = p -> rchild; // 并将右孩子压入栈
 */
void preOrder(Node *node) {
    stack<Node*> s;
    Node *p = node;
    while (p || !s.empty()) {
        if (p) {
            visit(p);
            s.push(p);
            p = p -> left;
        } else {
            p = s.top();
            s.pop();
            p = p -> right;
        }
    }
}

// 非递归实现中序遍历
void inOrder(Node *node) {
    stack<Node*> s;
    Node *p = node;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p -> left;
        } else {
            p = s.top();
            s.pop();
            visit(p);
            p = p -> right;
        }
    }
}

/**
 * 非递归的后序遍历
 * 1. 定义栈s实现非递归的后序遍历，并定义p与pre指针，依次分别根结点与上一次访问结点
 * 2. 若 p != null || !s.empty(), 反复执行第3、4步
 * 3. if (p != null) s.push(p); p = p -> lchild;  // 反复寻找当前结点的最左结点
 * 4. else
 *      p = s.top(); // 获取栈顶元素
 *      if (p -> rchild == null || p -> rchild == pre) visit(p); pre = p; s.pop(); p = NULL;  // 出队并记录该元素，并令p = null，以便进入下个结点
 *      else p = p -> rchild;
 */
void postOrder(Node *node) {
    stack<Node*> s;
    Node *p = node;
    Node *pre = NULL;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p -> left;  // 依次遍历左子树
        } else {
            p = s.top();
            // 若p的右孩子为空 或 p的右孩子等于上一次被访问的结点
            if (p -> right == NULL || p -> right == pre) {
                visit(p);   // 访问该结点
                pre = p;    // 将当前结点记录为pre
                s.pop();    // 当前结点出栈
                p = NULL;
            } else {
                p = p -> right; // 依次遍历右子树
            }
        }
    }
}

/**
 * 层序遍历(自下而上、从右到左)
 * 1. 定义队列q, 栈s, 先将根结点入队，并反复执行2、3、4步，直到队列为空
 * 2. Node *f = q.front(); q.pop(); // 将队首结点出队，并压入栈中
 * 3. 若f的左子树不为空，入队
 * 4. 若f的右子树不为空，入队
 * 5. 将栈中所有元素出栈
 */
void layerOrder(Node *node) {
    queue<Node*> q;
    stack<Node*> s;
    q.push(node);
    while (!q.empty()) {
        Node *f = q.front();
        s.push(f);
        q.pop();
        if (f -> left) {
            q.push(f -> left);
        }
        if (f -> right) {
            q.push(f -> right);
        }
    }
    while (!s.empty()) {
        visit(s.top());
        s.pop();
    }
}

/**
 * 非递归获取二叉树的高度
 *
 * 基于层序遍历获取树的高度
 */
int treeHeight(Node *node) {
    int level = 0;
    queue<Node*> q;
    node -> layer = 1;
    q.push(node);
    while (!q.empty()) {
        Node* f = q.front();
        // 获取队首结点的层次
        level = f -> layer;
        q.pop();
        if (f -> left) {
            f -> left -> layer = f -> layer + 1;
            q.push(f -> left);
        }
        if (f -> right) {
            f -> right -> layer = f -> layer + 1;
            q.push(f -> right);
        }
    }
    return level;
}

/**
 * 判断当前二叉树是否为完全二叉树(Complete Binary Tree)
 *
 * 分析：由于完全二叉树的性质（按从上到下、从左到右编号），故采用层序遍历的思想
 *
 * 1. 定义队列s, 将根结点入队, 再定义flag用于标识(队列中的结点是否都必为空结点), 并循环执行以下几步，直到队列为空
 * 2. 定义指针f 指向队首结点，并将其出队
 * 3. 若f 为空指针, 即遇到空结点后，队列中的元素都必须为空结点(令flag = true), 并跳过当前循环
 * 4. 若flag为true, 且当前结点不为空结点，则当前二叉树非完全二叉树, 并退出循环
 * 5. 将左右子树入队(不管其是否为空结点)
 */
bool cbt(Node *root) {
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
        Node *f = q.front();
        q.pop();
        if (f == nullptr) {
            flag = true;
            continue;
        }
        if (flag) return false;
        q.push(f -> left);
        q.push(f -> right);
    }
    return true;
}

// 计算二叉树中所有双分支结点的个数
int doubleNodeNum(Node *root) {
    int cnt = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* f = q.front();
        q.pop();
        if (f -> left && f -> right) {
            cnt++;
        }
        if (f -> left) {
            q.push(f -> left);
        }
        if (f -> right) {
            q.push(f -> right);
        }
    }
    return cnt;
}

// 将二叉树中各个子树的左右结点进行交换
void swapNode(Node *root) {
    if (root != NULL) {
        Node *temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        swapNode(root -> left);
        swapNode(root -> right);
    }
}

// 寻找先序序列中第k个结点的值
char findByIndex(Node *root, int k) {
    stack<Node*> s;
    Node *p = root;
    int i = 1;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            if (i == k) {
                return p -> data;
            }
            s.push(p);
            i++;
            p = p -> left;
        } else {
            p = s.top();
            s.pop();
            p = p -> right;
        }
    }
    return NULL;
}

/** 寻找值为x的结点，并将该结点及其所有的子结点删除并释放空间 **/

// 删除该子树
void removeX(Node *&root) {
    if (root -> left) {
        removeX(root -> left);
    }
    if (root -> right) {
        removeX(root -> right);
    }
    // 释放结点
    delete(root);
    // 并指向空指针
    root = NULL;
}

// 寻找值为x的结点, 并删除该子树
void findAndRemoveX(Node *&root, char x) {
    if (root != NULL) {
        if (root -> data == x) {
            removeX(root);
        } else {
            if (root -> left) {
                findAndRemoveX(root -> left, x);
            }
            if (root -> right) {
                findAndRemoveX(root -> right, x);
            }
        }
    }
}

/** end **/

/**
 * 找值为x的结点(假设只存在一个)的所有祖先结点
 *
 * 定义队列s对二叉树进行层序遍历，并去寻找值为x的结点
 * 1. 若队首结点的值不为x，则将其出队并入栈，并将其左右孩子入队
 * 2. 若队首结点的值为x，记指针f指向队首元素，并退出循环；
 * 3. 将栈中依次元素出栈，记指针t指向栈顶元素；
 * 4. 若t为f的父结点，输出t，并将f = t；反之则继续出栈
 */
void findAncestor(Node *root, int x) {
    queue<Node*> q;
    q.push(root);
    stack<Node*> s;
    Node *f;
    while (!q.empty()) {
        f = q.front();
        if (f -> data != x) {
            // 出队并入栈
            s.push(f);
            q.pop();
            if (f -> left) {
                q.push(f -> left);
            }
            if (f -> right) {
                q.push(f -> right);
            }
        } else {
            // 退出循环
            break;
        }
    }
    while (!s.empty()) {
        Node *t = s.top();
        s.pop();
        if (t -> right == f || t -> left == f) {
            visit(t);
            f = t;
        }
    }
}


/**
 * lca 寻找结点p、q的最近公共祖先
 *
 * 1. 对二叉树递归进行后序遍历(why? 因为后序遍历中，访问根结点时，其左右子树总是已读取到的)
 * 2. 递归边界: 当前结点root == null 或 root == p 或 root == q
 * 3. 递归取左右子树, 并定义left指针指向左子树, right指针指向右子树
 * 4. (由于递归的性质，此时已取得左右子树)，将会出现三种情况
 *      case 1: 若left == null, 返回 rchild (则结点q、p的最近公共祖先则出现在右子树上)
 *      case 2: 若right == null, 返回 lchild
 *      case 3: lchild 与 right都不为空, 则返回 root
 */
Node* lowestCommonAncestor(Node *root, Node *p, Node *q) {
    if (root == nullptr || root == p || root == q) return root;
    Node *left = lowestCommonAncestor(root -> left, p, q);
    Node *right = lowestCommonAncestor(root -> right, p, q);
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    return root;
}

/**
 * 寻找二叉树的最大宽度(二叉树的各个层次的最大结点总数)
 *
 * 基于层序遍历，并将树分层，由此来统计各个层次的结点总数
 */
int findMaxBreadth(Node *root) {
    queue<Node*> q;
    q.push(root);
    root -> layer = 1;
    stack<Node*> s;
    while (!q.empty()) {
        Node* f = q.front();
        q.pop();
        s.push(f);
        if (f -> left != nullptr) {
            f -> left -> layer = f -> layer + 1;
            q.push(f -> left);
        }
        if (f -> right != nullptr) {
            f -> right -> layer = f -> layer + 1;
            q.push(f -> right);
        }
    }
    int max = 1, layer, cnt = 0;
    while (!s.empty()) {
        Node *t = s.top();
        s.pop();
        if (t -> layer != layer) {
            layer = t -> layer;
            if (cnt > max) {
                max = cnt;
            }
            cnt = 0;
        }
        cnt++;
    }
    return max;
}

// 设有一棵满二叉树，给定其先序序列，求后序序列
void work15(char pre_[], int preL, int preR, char post_[], int postL, int postR) {
    if (preL <= preR) {
        post_[postR] = pre_[preL];
        int mid = (preR - preL) / 2;
        // 处理左子树
        work15(pre_, preL + 1, preL + mid, post_, postL, postL + mid - 1);
        // 处理右子树
        work15(pre_, preL + mid + 1, preR, post_, postL + mid, postR - 1);
    }
}

Node *head, *prev_;
void work16(Node *root) {
    if (root != NULL) {
        if (root -> left == NULL && root -> right == NULL) {
            if(head == NULL) {
                head = root;
                prev_ = head;
            } else {
                prev_ -> right = root;
                prev_ = root;
            }
        }
        work16(root -> left);
        work16(root -> right);
    }
}

/**
 * 判断两棵树是否相似
 *
 * 1. 采用递归的方式判断两棵二叉树树是否相似
 * 2. 递归边界: 若 当前两个结点都为空 返回 true;  若一个结点为空而另一个不为空 返回 false
 * 3. 递归体: 继续进行对当前结点的左右子树进行递归
 */
bool similarTree(Node *A, Node *B) {
    if (A == NULL && B == NULL) {
        return true;
    } else if (A == NULL || B == NULL) {
        return false;
    }
    bool fl = similarTree(A -> left, B -> left);
    bool fr = similarTree(A -> right, B -> right);
    return fl && fr;
}

int main() {
    Node *node = NULL;
    // 手动创建二叉树
    // createNode(node);

    // 中序序列与后序序列构建二叉树
    // node = createInPost(0, 4, 0, 4);

    node = createPreIn(0, 5, 0, 5);

    cout << node;
/*
    printf("是否为完全二叉树: %d\n", cbt(node));

    printf("二叉树中所有双分支结点的个数: %d\n", doubleNodeNum(node));

    printf("寻找第k个结点的值: %c\n", findByIndex(node, 5));

    // 输出值为x的所有祖先结点
    findAncestor(node, 'D');
    printf("\n");

    printf("最近公共祖先：%c\n", lowestCommonAncestor(node, node -> left -> left, node -> left -> right) -> data);

    printf("最大宽度: %d\n", findMaxBreadth(node));

    char pre_[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char post_[7];
    work15(pre_, 0, 6, post_, 0, 6);

    work16(node);

    printf("两棵树是否相似：%d\n", similarTree(node, node));
    // findAndRemoveX(node, 'D');
    // swapNode(node);

    preOrder(node);
    printf("\n");
    inOrder(node);
    printf("\n");
    postOrder(node);

    printf("\n");
    layerOrder(node);

    printf("\n");
    printf("tree height: %d", treeHeight(node));*/
    return 0;
}