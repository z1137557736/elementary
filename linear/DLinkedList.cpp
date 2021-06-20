#include <cstdio>

/**
 * 双向链表(带头结点，即头结点不含数据)的基本操作
 * @author stan
 */

struct DNode {
    int data;   // 数据域
    DNode *prev, *next; // 前继与后继指针
};

// 头插法创建双向链表;时间复杂度为:O(n)
DNode* createPre(int arr[]) {
    DNode *head = new DNode;
    head -> next = NULL;
    head -> prev = NULL;
    for (int i = 0; i < 5; i++) {
        // 创建待插入结点
        DNode *next = new DNode;
        next -> data = arr[i];
        next -> next = head -> next;
        if (head -> next != NULL) {
            // 后继结点指向前驱
            head -> next -> prev = next;
        }
        head -> next = next;
        next -> prev = head;
        // 更新头结点
        head -> next = next;
    }
    return head;
}

// 尾插法创建双向链表;时间复杂度为:O(n)
DNode* createTail(int arr[]) {
    // 链表的头部结点
    DNode *head = new DNode;
    head -> prev = NULL;
    // 链表的尾部结点
    DNode *last = head;
    for (int i = 0; i < 5; i++) {
        // 创建待插入结点
        DNode *next = new DNode;
        next -> data = arr[i];
        // 初始化后继结点为空
        next -> next = NULL;
        // 前驱结点指后继
        last -> next = next;
        // 后继结点指前驱
        next -> prev = last;
        // last始终指向尾部结点
        last = next;
    }
    // 返回头结点
    return head;
}

// 将数据域为x的结点插入到索引index上，时间复杂度:O(n)
void insert(DNode *head, int index, int x) {
    DNode *next = head -> next;
    // 寻找到索引为index的结点
    for (int i = 0; i < index; i++) {
        next = next -> next;
    }
    // 创建待插入结点
    DNode *node = new DNode;
    node -> data = x;
    // 添加两条链
    node -> next = next;
    node -> prev= next -> prev;
    // 变更两条链
    next -> prev -> next = node;
    next -> prev = node;
}

// 删除索引为index的结点，时间复杂度:O(n)
void remove(DNode *head, int index) {
    DNode *next = head ->  next;
    // 寻找到索引为index的结点
    for (int i = 0; i < index; i++) {
        next = next -> next;
    }
    // 变更两条链
    next -> prev -> next = next -> next;
    next -> next -> prev = next -> prev;
    // 释放内存
    delete(next);
}

void printNode(DNode *head) {
    DNode *next = head -> next;
    while (next != NULL) {
        printf("%d ", next -> data);
        next = next -> next;
    }
    printf("\n");
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    DNode *head = createTail(A);
    printNode(createPre(A));
    printNode(head);
    insert(head, 1, 6);
    printNode(head);
    remove(head, 2);
    printNode(head);
}
