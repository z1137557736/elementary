#include <cstdio>

struct Node {
    int data;
    Node *next; // 指针变量（用于存放内存地址）指针也就是内存地址
};

// 尾插法创建不带头结点
Node* createTail(int arr[]) {
    // 头指针
    Node *head = new Node;
    // 特判
    head -> data = arr[0];
    // 尾指针
    Node *last = head;
    for (int i = 1; i < 5; i++) {
        // 创建待插入结点
        Node *next = new Node;
        next -> data = arr[i];
        // 指针变量指向空指针
        next -> next = NULL;
        // 尾插指针变量
        last -> next = next;
        // 更新尾指针变量
        last = next;
    }
    return head;
}

// 不带头结点的单链表，递归删除单链表中所有值为x的结点
void remove(Node* &node, int x) {
    // 递归边界
    if (node == NULL) {
        return;
    }
    // 判断是否为待删除结点
    if (node -> data == x) {
        Node *p = node;
        // 将当前指针变量的内存地址修改为其后继结点的内存地址
        node = node -> next;
        // 删除结点
        delete(p);
        remove(node, x);
    } else {
        remove(node -> next, x);
    }
}

void printNode(Node *head) {
    Node *next = head;
    while (next != NULL) {
        printf("%d ", next -> data);
        next = next -> next;
    }
    printf("\n");
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    Node *head = createTail(A);
    remove(head, 2);
    printNode(head);
}