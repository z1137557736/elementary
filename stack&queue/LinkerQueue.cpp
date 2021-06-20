#include <cstdio>

// 单链表
struct LinkedList {
    int data;
    LinkedList *next;
};

// 链式队列
struct LinkedQueue {
    // (带头结点)头指针 和 尾指针
    LinkedList *front, *rear;
};

// 初始化链表
LinkedQueue* init() {
    LinkedQueue *Q = new LinkedQueue;
    Q -> front = Q -> rear = new LinkedList;
    Q -> front -> next = NULL;
    return Q;
}

// 判断是否为空队列
bool empty(LinkedQueue *Q) {
    return Q -> front == Q -> rear;
}

// 入队，无限制
bool push(LinkedQueue *&Q, int x) {
    LinkedList *node = new LinkedList;
    node -> data = x;
    node -> next = NULL;
    // 尾插法思想
    Q -> rear -> next = node;
    Q -> rear = node;
    return true;
}

// 出队，需判断是否为空队列
bool pop(LinkedQueue *&Q, int &x) {
    // 空队列
    if (empty(Q)) return false;
    LinkedList *next = Q -> front -> next;
    // 通过引用传递将数据投出去
    x = next -> data;
    // 移动指针
    Q -> front -> next = next -> next;
    // 若next结点为最后一个结点
    if (next == Q -> rear) {
        Q -> rear = Q -> front;
    }
    delete(next);
    return true;
}

