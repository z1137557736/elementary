#include <cstdio>

/**
 * 单链表(带头结点，即头结点不含数据)的基本操作
 * @author stan
 */

struct Node {
    int data;   // 数据域
    Node *next; // 指针域
};

// 头插法创建单链表(即新加入的元素都在最前面)，时间复杂度:O(n)
Node* createPre(int arr[]) {
    // 定义头结点与next结点
    Node *head, *next;
    // 创建head结点
    head = new Node;
    // 初始化为空链表(设置最后一个结点的指针域为NULL)
    head -> next = NULL;
    for (int i = 0; i < 5; i++) {
        next = new Node;
        next -> data = arr[i];
        // 将next的指针域指向了头结点的指针域
        next -> next = head -> next;
        // 重新将头结点的指针域指向next知怎
        head -> next = next;
    }
    return head;
}

// 不带头结点头插法创建单链表，时间复杂度:O(n)
Node* test(int arr[]) {
    // 定义head
    Node *head, *next;
    // 令头结点为空
    head = NULL;
    for (int i = 0; i < 5; i++) {
        // 创建next结点
        next = new Node;
        // 赋值
        next -> data = arr[i];
        // next结点的指针域指向头结点的指针
        next -> next = head;
        // 令head指针指向next
        head = next;
    }
    return head;
}

// 尾插法建立单链表(即新插入的元素在最后面)，时间复杂度:O(n)
Node* createTail(int arr[]) {
    Node *head, *pre, *next;
    // 初始化head结点
    head = new Node;
    // pre指向head指针
    pre = head;
    for (int i = 0; i < 5; i++) {
        // 初始化next结点
        next = new Node;
        next -> data = arr[i];
        // next指针域默认为空
        next -> next = NULL;
        // pre结点的指针域指向next结点的指针
        pre -> next = next;
        // 将pre指向next的指针
        pre = next;
    }
    return head;
}

// 根据索引获取结点，时间复杂度:O(n)
Node* get(Node *head, int i) {
    Node *next = head -> next;
    if (i < 0) {
        printf("illegal parameter");
        return NULL;
    }
    int j = 0;
    // 如当前结点不为空结点
    while (next != NULL) {
        // 找到对应索引元素
        if (j == i) {
            break;
        }
        // 指向下一个指针域
        next = next -> next;
        j++;
    }
    return next;
}

// 按值查找结点，时间复杂度:O(n)
Node* getValue(Node *head, int x) {
    Node *next = head -> next;
    // 遍历链表
    while (next != NULL) {
        // 对应值的结点
        if (next -> data == x) {
            return next;
        }
        // 指向其指针域
        next = next -> next;
    }
    // 无对应结点
    return NULL;
}

// 将数据域为x的结点插入到索引index上，时间复杂度:O(n)
void insert(Node *head, int index, int x) {
    if (index < 0) {
        printf("illegal parameter");
        return;
    }
    // 获取索引为index - 1的结点（即索引index的前一个结点）
    Node *pre = head;
    for (int i = 0; i < index; i++) {
        // 指向索引为index的结点
        pre = pre -> next;
    }
    // 初始化新建结点
    Node *node = new Node;
    // 赋值
    node -> data = x;
    // 添加一条链
    node -> next = pre -> next;
    // 变更一条链
    pre -> next = node;
}

// 删除索引为index的结点，时间复杂度:O(n)
void remove(Node *head, int index) {
    if (index < 0) {
        printf("illegal parameter");
        return;
    }
    Node *pre = head;
    // 找索引为index的前一个元素
    for (int i = 0; i < index; i++) {
        pre = pre -> next;
    }
    // 记录待删除结点
    Node *next = pre -> next;
    // 变更一条链
    pre -> next = next -> next;
    // 释放内存
    delete(next);
}

// 根据给定值删除结点，时间复杂度:O(n)
void removeValue(Node *head, int x) {
    // 待删除结点
    Node *next = head -> next;
    // 记录待删除的结点的前驱结点
    Node *pre = head;
    // 遍历链表
    while (next != NULL) {
        if (next -> data == x) {
            pre -> next = next -> next;
            // 释放内存
            delete(next);
            // 退出循环
            break;
        } else {
            // 更新前驱结点
            pre = next;
            // 更新待删除结点
            next = next -> next;
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

int main() {
    int A[] = {1, 2, 3, 4, 5};
    printNode(createPre(A));
    Node *head = createTail(A);
    printNode(head);
    insert(head, 0, 9);
    printNode(head);
    remove(head, 2);
    printNode(head);
    removeValue(head, 4);
    printNode(head);
    printf("%d", get(head, 0) -> data);
    printf("%d", getValue(head, 5) -> data);
}