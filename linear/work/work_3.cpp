#include <cstdio>
#include <cstdlib>
#include <cstring>

// 双链表
struct DLinkedList {
    int data;   // 数据域
    int freq;   // 访问次数
    DLinkedList *prev;   // 前驱结点
    DLinkedList *next; // 后继结点（用于存放内存地址）
};

// （带头结点）循环单链表，采用尾指针法
struct LinkedList {
    int data;
    LinkedList *next;   // 后继结点
};

// 尾插法创建循环双链表
DLinkedList* createTail(int arr[], int n) {
    DLinkedList *head = new DLinkedList;
    head -> prev = NULL;
    DLinkedList *last = head;
    for (int i = 0; i < n; i++) {
        // 初始化参数
        DLinkedList *node = new DLinkedList;
        node -> next = NULL;
        node -> data = arr[i];
        node -> freq = 1;
        // 开始尾插法
        last -> next = node;
        node -> prev = last;
        last = last -> next;
    }
    // 循环双链表
//    last -> next = head;
//    head -> prev = last;
    return head;
}

LinkedList* createTail2(int arr[], int n) {
    LinkedList *head = new LinkedList;
    LinkedList *last = head;
    for (int i = 0; i < n; i++) {
        // 开始尾插法
        LinkedList *node = new LinkedList;
        node -> next = NULL;
        node -> data = arr[i];
        last -> next = node;
        last = last -> next;
    }
    // 循环单链表
    // last -> next = head;
    // 返回尾指针
    // return last;
    // 返回头指针
    // 创建环
    // last -> next = head -> next -> next;
    return head;
}


/** Q17: 判断循环双链表是否对称，即以链表的中心为对称轴对应位置的左右结点值相等 **/

bool work17(DLinkedList *head) {
    DLinkedList *first = head -> next;
    DLinkedList *last = head -> prev;
    // 奇数个结点时，为 first != last为递推条件
    // 偶数个结点是，为 last -> next != first 为递推条件
    while (first != last && last -> next != last) {
        if (first -> data == last -> data) {
            first = first -> next;
            last = last -> prev;
        } else {
            return false;
        }
    }
    return true;
}

/** Q18: 合并两个循环单链表，并仍保持循环链表的形式 **/

// 画图是个好习惯！
void work18(LinkedList *&A, LinkedList *B) {
    LinkedList *nextB = B -> next -> next;
    // 暂存A的带头结点
    LinkedList *headA = A -> next;
    // 递推条件：nextB不等于带头结点即可
    while (nextB != B -> next) {
        A -> next = nextB;
        A = nextB;
        nextB = nextB -> next;
    }
    // 恢复为循环单链表
    A -> next = headA;
}

/** Q19: 反复找出循环单链表中最小元素，进行输出并删除，直到单链表为空，再删除头结点 **/

void work19(LinkedList *head) {
    // 注意循环单链表的边界条件
    while (head -> next != head) {
        // 反复初始化最小结点 p为工作结点 最小值的前驱结点
        LinkedList *next = head -> next, *min = next, *q = head, *prev = head;
        // 寻找最小元素
        while (next != head) {
            // p与最小元素比大小
            if (next -> data < min -> data) {
                min = next;
                // 记录最小元素的前驱结点
                prev = q;
            }
            next = next -> next;
            q = q -> next;
        }
        // 输出并删除最小元素
        printf("%d ", min -> data);
        prev -> next = min -> next;
        // 释放内存
        delete(min);
    }
    delete(head);
}

/** Q20: 非循环双向链表：每次按值查询x时，freq加1，且链表按访问频度递减排序；若freq相同，则按最近访问的在前。  **/

// 考察双向链表的插入与查询
DLinkedList* work20(DLinkedList *head, int x) {
    DLinkedList *next = head -> next;
    while (next != NULL) {
        if (next -> data == x) {
            // 访问频度加1
            next -> freq++;
            // 工作结点用于寻找其前驱结点
            DLinkedList *p = next -> prev;
            while (p != head && p -> freq <= next -> freq) {
                // 往前搜索恰当的前驱结点
                p = p -> prev;
            }
            // 前移结点
            if (p != next -> prev) {
                // 将其从之前所在位置取出
                next -> prev -> next = next -> next;
                next -> next -> prev = next -> prev;
                // 插入元素
                next -> prev = p;
                next -> next = p -> next;
                p -> next -> prev = next;
                p -> next = next;
            }
            // 退出循环
            break;
        }
        // 进位
        next = next -> next;
    }
    return next;
}


// 双指针法，寻找尾部的第k个结点
int work21(LinkedList *head, int k) {
    // 1. 定义p q指针指向第一个结点
    LinkedList *p = head -> next, *q = head -> next;
    // 2. count用于记录p所移动指针的次数
    int cnt = 0;
    if (k < 1) {
        return 0;
    }
    // 3. 将p指针移动到第k个结点上
    while (p != NULL) {
        // 4. 此时p与q同时向前移动，直到p指针指向空结点（即最后一个结点）
        if (cnt >= k)
            q = q -> next;
        p = p -> next;
        cnt++;
    }
    if (cnt < k) {
        return 0;
    }
    // 5. 因为q与p相差k个结点，此时q指向的就为倒数第k个结点
    printf("%d", q -> data);
    return 1;
}

int _size(LinkedList *head) {
    int size = 0;
    LinkedList *next = head -> next;
    while (next != NULL) {
        size++;
        next = next -> next;
    }
    return size;
}

LinkedList* work22(LinkedList *A, LinkedList *B) {
    // 1. 分别获取A、B单链表的长度，并依次记作n，m
    int n = _size(A), m = _size(B);
    // 2. 定义p、q指针依次指向A与B的第一个结点
    LinkedList *p = A -> next, *q = B -> next;
    // 3. 若n < m，则将q指针移动第m - n + 1个结点上
    while (n < m) {
        q = q -> next;
        m--;
    }
    // 若 m < n,则将p指针移动到第n - m + 1个结点上
    while (m < n) {
        p = p -> next;
        n--;
    }
    // 4. 反复将p、q指针向后移动，若p、q指针指向同一指针时，则该指针为共同后缀的起始位置，算法结束
    while (p != NULL && p != q) {
        p = p -> next;
        q = q -> next;
    }
    return p;
}

// 取绝对值
int _abs(int num) {
    if (num < 0) {
        num = -num;
    }
    return num;
}

// 时间复杂度: O(n) 空间复杂度: O(n)
void work23(LinkedList *head, int n) {
    // 1. 定义长度为n的动态数组d用于标识结点数据是否为第一次出现，并初始化标记为0，数组下标i = |data| - 1
    int *d = (int*) malloc(sizeof(int) * n);
    memset(d, 0, n);
    LinkedList *next = head -> next, *pre = head;
    while (next != NULL) {
        int i = _abs(next -> data) - 1;
        // 2. 若d[i]为0时，则为第一次出现，并标记为1；反之则删除该结点
        if (d[i] == 0) {
            d[i] = 1;
            next = next -> next;
            pre = pre -> next;
        } else {
            pre -> next = next -> next;
            delete(next);
            next = pre -> next;
        }
    }
    delete(d);
}



void printList(LinkedList *head) {
    LinkedList *next = head -> next;
    // 循环单链表是个环，递推条件：只要不等于带头结点即可
    while (next != NULL) {
        printf("%d ", next -> data);
        next = next -> next;
    }
    printf("\n");
}

// work 24: 判断链表是否有环，若有环，请给出环的入口并返回
LinkedList* detectCycle(LinkedList *head) {
    // 1. 定义fast与slow指针，都指向链表头部
    LinkedList *fast, *slow;
    fast = slow = head;
    while (true) {
        // 只要fast或fast的后继结点为空，则无环
        if (fast == NULL || fast -> next == NULL) return NULL;
        // 2. fast每次移动两步 slow每次移动一步
        fast = fast -> next -> next;
        slow = slow -> next;
        // 3. fast == slow 则链表存在环
        if (fast == slow) break;
    }
    // 4. 定义p指针指向头结点，当p移动a个结点时，slow也移动了a个结点，因此p和slow都会指向环入口的结点，即 p == slow
    LinkedList *p = head;
    // k = a + nb = a + s 其中a为头结点到环入口结点的距离
    while (p != slow) {
        p = p -> next;
        slow = slow -> next;
    }
    return p;
}

// 将带头结点的单链表首尾交叉排序
void work25(LinkedList *head) {
    // 用双指针求链表的中间结点
    // 1. 定义fast slow结点指向链表头部，其中fast每次走两步，slow每次走一步，当fast走到末尾时，slow就走到了第n / 2个结点
    LinkedList *fast, *slow, *first, *middle;
    fast = slow = head;
    while (true) {
        if (fast == NULL || fast -> next == NULL) break;
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    // 2. 而中间结点为第(n / 2) + 1个结点，即slow = slow -> next，则slow为中间结点
    // 如中位数为 3 / 2 + 1= 2; 4 / 2 + 1 = 3
    fast = slow -> next;
    // slow 也为带头结点
    slow -> next = NULL;
    // 使用栈逆置的话也属于空间复杂度
    // 3. 就地逆置(头插法)slow所指向的链表，便于取尾结点
    while (fast != NULL) {
        LinkedList *node = fast;
        fast = fast -> next;
        // 头插法
        node -> next = slow -> next;
        slow -> next = node;
    }
    // 4. 将逆置链表插入到原链表中
    first = head -> next;
    middle = slow -> next;
    slow -> next = NULL;
    while (middle != NULL) {
        // 继续采用头插法的思想
        LinkedList *node = middle;
        middle = middle -> next;
        node -> next = first -> next;
        first -> next = node;
        first = node -> next;
    }
    return;
}

void printList2(DLinkedList *head) {
    DLinkedList *next = head -> next;
    // 循环单链表是个环，递推条件：只要不等于带头结点即可
    while (next != NULL) {
        printf("%d ", next -> data);
        next = next -> next;
    }
    printf("\n");
}


int main() {
    int A[] = {50, 15, -15, -7, 7, 8};
    int B[] = {3, 4, 5};
    LinkedList *head = createTail2(A, 6);
    LinkedList *head2 = createTail2(B, 3);

    DLinkedList *head3 = createTail(A, 6);

    // work 17
    // printf("%d", work17(createTail(A, 4)));

    // work 18;
//    work18(tail1, tail2);
//    printList(tail1);

    // work 19
    // work19(head);

    // work 20
//    printList2(head2);
//    work20(head2, 3);
//    work20(head2, 3);
//    work20(head2, 1);
//    work20(head2, 2);
//    work20(head2, 2);
//    // printf("%d", t1 -> data);
//    printList2(head2);

    // work21(head, 7);

//    // work 22
//    LinkedList *head3 = head -> next -> next;
//    printf("%d", work22(head, head3) -> data);

    // work 23
//    work23(head, 50);
//    printList(head);

    // work 24
//  detectCycle(head);

    // work 25
    work25(head);
}