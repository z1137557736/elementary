#include <cstdio>

struct Node {
    int data;
    Node *next; // 指针变量（用于存放内存地址）指针也就是内存地址
};

// 尾插法创建带头结点
Node* createTail(int arr[], int n) {
    // 头指针
    Node *head = new Node;
    // 尾指针
    Node *last = head;
    for (int i = 0; i < n; i++) {
        // 创建待插入结点
        Node *next = new Node;
        next -> data = arr[i];
        // 指针变量指向空指针
        next -> next = NULL;
        // 尾部插入后继结点
        last -> next = next;
        // 更新尾指针变量
        last = next;
    }
    return head;
}

int size(Node *head) {
    int i = 0;
    Node *next = head -> next;
    while (next != NULL) {
        i++;
        next = next -> next;
    }
    return i;
}

/** Q2：删除head结点中数据域为x的结点 **/

// 方法一（采用记录前驱结点来更新链表之间的关系，旨在不断链）
void remove1(Node *head, int x) {
    // pre为待删除结点的前驱指针，next为待删除结点指针
    Node *prev = head, *next = head -> next;
    while (next != NULL) {
        if (next -> data == x) {
            // 删除中间结点，其前驱链其后继结点
            prev -> next = next -> next;
            delete(next);
            next = prev -> next;
        } else {
            next = next -> next;
            prev = prev -> next;
        }
    }
}

// 方法二（用尾插法创建单链表，即重新分配各个指针变量所保存的内存地址）
void remove2(Node* &head, int x) {
    Node *next = head -> next, *last = head;
    while (next != NULL) {
        if (next -> data != x) {
            // 尾插法(更新内存地址)
            last -> next = next;
            // 更新last尾指针
            last = next;
            next = next -> next;
        } else {
            Node *temp = next;
            next = next -> next;
            delete(temp);
        }
    }
    // 尾结点指向空指针
    last -> next = NULL;
}

/** Q3: 带头结点单链表--从尾到头输出每个结点的值 **/

// 采用递归法可倒序输出链表
void printNode3(Node *node) {
    // 递归边界
    if (node -> next != NULL) {
        printNode3(node -> next);
        // Note：由于是带头结点，这里每次输出都是其后继结点的值
        printf("%d ", node -> next -> data);
    }
}

/** Q4: 带头结点单链表--删除一个最小值结点 **/

const int INF = 0x7fffffff;

void removeMin3(Node *head) {
    int min = INF;
    // 记录最小值结点
    Node *p;
    Node *next = head -> next, *pre = head;
    // 寻找最小值结点
    while (next != NULL) {
        if (next -> data < min) {
            min = next -> data;
            p = next;
        }
        next = next -> next;
    }
    // 删除最小值结点
    next = head -> next;
    while (next != NULL) {
        // 匹配最小值结点
        if (next -> data == p -> data) {
            pre -> next = next -> next;
            // 删除结点，即释放内存
            delete(next);
            // 退出循环
            break;
        } else {
            next = next -> next;
            pre = pre -> next;
        }
    }
}

/** Q5: 带头结点单链表--就地逆置 **/

// 采用头插法，逆置单链表
Node* reverse4(Node* head) {
    Node *next = head -> next, *first = head;
    first -> next = NULL;
    while (next != NULL) {
        // 暂存结点
        Node *node = next;
        // 偏移结点
        next = next -> next;
        // 头插法
        node -> next = first -> next;
        first -> next = node;
    }
    return first;
}

/** Q6: 带头结点单链表--使其元素递增有序， todo **/

// 采用插入法思想，时间复杂度为O(nˆ2)
Node* sort6(Node* head) {
}

/** Q7: 带头结点单链表--删除无序单链表中介于给定的两个值的所有元素 **/

// (p, q)范围
void removeRange7(Node* head, int p, int q) {
    Node *next = head -> next, *pre = head;
    while (next != NULL) {
        // 在待删除数据范围之类
        if (p < next -> data && next -> data < q) {
            pre -> next = next -> next;
            delete(next);
            next = pre -> next;
        } else {
            pre = pre -> next;
            next = next -> next;
        }
    }
}

/** Q8: 给定两个带头结点单链表，并返回其公共结点(即指针相同的结点)
 * 注意到若有公共结点，则从某一项开始，后面的项都相同，则只需判断从哪一项结点相等时即得到我们的结果
 * **/


Node* work8(Node *A, Node *B) {
    int n = size(A), m = size(B), k;
    // 定义长链表与短链表
    Node *longNode, *shortNode;
    // 记录两个链表长度的
    if (n <= m) {
        k = m - n;
        longNode = B -> next;
        shortNode = A -> next;
    } else {
        k = n - m;
        longNode = A -> next;
        shortNode = B -> next;
    }
    // 保持与shortNode长度一致
    while (k--) {
        longNode = longNode -> next;
    }
    while (longNode != NULL) {
        // 找到共同结点
        if (longNode == shortNode) {
            return longNode;
        } else {
            longNode = longNode -> next;
            shortNode = shortNode -> next;
        }
    }
    // 无共同结点
    return NULL;
}

/** Q9: 递增次序输出单链表中各结点的数据元素，并释放其空间 **/

// 思路：每次找到最小值，输出并删除，时间复杂度为O(nˆ2)
void remove9(Node *&head) {
    while (head != NULL) {
        Node *next = head -> next, *pre = head;
        int min = INF;
        // 待删除结点及其前驱结点
        Node *r = NULL, *p;
        // 寻找最小值
        while (next != NULL) {
            if (next -> data < min) {
                min = next -> data;
                r = next;
                p = pre;
            }
            // 进位
            next = next -> next;
            pre = pre -> next;
        }
        // 即无最小值，只剩下带头结点
        if (r == NULL) {
            head = NULL;
            delete(head);
            printf(" clear");
        } else {
            // 变更链
            p -> next = r -> next;
            printf("%d ", r -> data);
            // 释放内存
            delete(r);
        }
    }
}

void printNode(Node *head) {
    Node *next = head -> next;
    while (next != NULL) {
        printf("%d ", next -> data);
        next = next -> next;
    }
    printf("\n");
}

/** Q10: 将带头结点的单链表A，分解为两个单链表A与B，其中A为奇次项，B为偶次项 **/

// A用删除法，B用尾插法
Node* work10(Node *&A) {
    Node *B = new Node, *pre = A, *next = A -> next;
    B -> next = NULL;
    Node *last = B;
    int i = 1;
    while (next != NULL) {
        // 偶次项
        if (i % 2 == 0) {
            // 尾插法
            last -> next = next;
            last = next;
            // 偶次项从A中移除
            pre -> next = next -> next;
            next = next -> next;
        } else {
            // 奇次项(进位即可)
            next = next -> next;
            pre = pre -> next;
        }
        i++;
    }
    // 置空由指针而导致的冗余后继结点
    last -> next = NULL;
    return B;
}

/** Q11: 带头结点的单链表C，拆分为两个线性表，A为奇次项，B为偶次项并倒序 **/

// A使用删除法，B使用头插法
Node* work11(Node *&A) {
    Node *B = new Node;
    B -> next = NULL;
    Node *next = A -> next, *pre = A;
    int i = 1;
    while (next != NULL) {
        // 偶次项
        if (i++ % 2 == 0) {
            // 暂存的指针变量
            Node *node = next;
            next = next -> next;
            // 头插法逆置链表
            node -> next = B -> next;
            B -> next = node;
            // A删除偶次项
            pre -> next = next;
        } else {
            // 进位
            pre = pre -> next;
            next = next -> next;
        }
    }
    return B;
}

/** Q12: 带头结点的递增有序单链表A，删除其重复值  **/

void work12(Node *&head) {
    Node *first = head -> next;
    // 只存在一个元素，无重复值
    if (first -> next == NULL) {
        return;
    }
    // 画图思考
    Node *next = first -> next;
    while (next != NULL) {
        if (first -> data != next -> data) {
            first -> next = next;
            first = next;
            next = next -> next;
        } else {
            // 记录待删除结点
            Node *temp = next;
            next = next -> next;
            delete(temp);
        }
    }
}

/** Q13: 将带头结点的递增有序单链表A B归并为递减有序单链表C  **/

// 由于单链表有序，利用头插法即可变为递减序列
void work13(Node *&A, Node *&B) {
    Node *nextA = A -> next, *nextB = B -> next;
    Node *C = new Node;
    C -> next = NULL;
    // 临时结点，用于记录指针
    Node *temp;
    // 保证两个结点都不为空
    while (nextA != NULL && nextB != NULL) {
        // 链表逆置法
        if (nextA -> data < nextB -> data) {
            temp = nextA;
            nextA = nextA -> next;
            temp -> next = C -> next;
            C -> next = temp;
        } else {
            temp = nextB;
            nextB = nextB -> next;
            temp -> next = C -> next;
            C -> next = temp;
        }
    }
    while (nextA != NULL) {
        temp = nextA;
        nextA = nextA -> next;
        temp -> next = C -> next;
        C -> next = temp;
    }
    while (nextB != NULL) {
        temp = nextB;
        nextB = nextB -> next;
        temp -> next = C -> next;
        C -> next = temp;
    }
    // A B 存放归并后的结点
    A = C;
    B = C;
}

/** Q14: 设有带头结点的两个单链表A、B，从A B中选出公共元素作为C的结点 **/

// 画图思考：定义两个工作指针nextA，nextB，分别用于遍历A与B。若nextA的值小于nextB的值，则nextA进位，反之同理
Node* work14(Node *A, Node *B) {
    Node *nextA = A -> next, *nextB = B -> next,
        *C = new Node;
    // 尾插法
    Node *last = C;
    while (nextA != NULL && nextB != NULL) {
        if (nextA -> data < nextB -> data) {
            nextA = nextA -> next;
        } else if (nextA -> data > nextB -> data) {
            nextB = nextB -> next;
        } else {
            // 尾插法
            Node *n = new Node;
            n -> next = NULL;
            n -> data = nextB -> data;
            last -> next = n;
            last = n;
            // nextA nextB 进位
            nextB = nextB -> next;
            nextA = nextA -> next;
        }
    }
    return C;
}

/** Q15: 设有带头结点的两个单链表A、B，将A与B的交集并入链表A中 **/

// 跟上一题思路一样，只是把值存放到A中
void work15(Node *&A, Node *B) {
    Node *nextA = A -> next, *nextB = B -> next,
    *last = A;
    while (nextA != NULL && nextB != NULL) {
        if (nextA -> data < nextB -> data) {
            nextA = nextA -> next;
        } else if (nextA -> data > nextB -> data) {
            nextB = nextB -> next;
        } else {
            // 找到A与B的交集
            // 尾插法
            last -> next = nextB;
            last = nextB;
            nextB = nextB -> next;
            nextA = nextA -> next;
        }
    }
    // 置空后继结点
    last -> next = NULL;
}

/** Q16: 设有带头结点的两个单链表A、B，判断B是否是A的子序列 **/

// 画图解决一切
bool work16(Node *A, Node *B) {
    Node *nextA = A -> next, *nextB = B -> next;
    // 寻找与B相同的起始结点
    while (nextA != NULL) {
        if (nextA -> data == nextB -> data) {
            nextA = nextA -> next;
            nextB = nextB -> next;
            // 跳出循环
            break;
        }
        nextA = nextA -> next;
    }
    while (nextA != NULL && nextB != NULL) {
        // 不相同
        if (nextA -> data != nextB -> data) {
            break;
        }
        // 进位
        nextA = nextA -> next;
        nextB = nextB -> next;
    }
    // 若nextB能遍历到尾部，则说明B是A的子序列
    return nextB == NULL;
}



int main() {
    int A[] = {1, 3, 4, 6, 7, 8};
    int B[] = {1, 3, 4, 6};
    Node *head = createTail(A, 6);
    Node *head2 = createTail(B, 4);
    // removeMin3(head);
    // printNode(head);
    // removeRange7(head, 2, 5);
    // printNode(work8(head, head -> next));
    // remove9(head);

    // work10
    /*Node *B = work10(head);
    printNode(head);
    printNode(B);*/

    // work11
//    Node *B = work11(head);
//    printNode(head);
//    printNode(B);

    // work12
   /* work12(head);
    printNode(head);*/

    // work13
//    work13(head, head2);
//    printNode(head);

    // work 14
    // printNode(work14(head, head2));

    // work 15
//    work15(head, head2);
//    printNode(head);

    // work 16
    printf("%d", work16(head, head2));

    /*remove2(head, 2);
    remove1(head, 1);
    printNode(head);*/
}