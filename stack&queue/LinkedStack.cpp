#include <cstdio>

// 链栈
struct LinkedList {
    char data;
    LinkedList *next;
};

// 出栈
LinkedList* pop(LinkedList *&head) {
    LinkedList *p = head;
    head = head -> next;
    return p;
}

// 入栈
bool push(LinkedList *&head, int x) {
    LinkedList *node = new LinkedList;
    node -> data = x;
    node -> next = head;
    head = node;
    return true;
}

// 初始化栈
LinkedList* init(char arr[]) {
    LinkedList *head = new LinkedList;
    int i = 0;
    while (arr[i] == '\0') {
        push(head, arr[i]);
        i++;
    }
    return head;
}