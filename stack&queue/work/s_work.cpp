#include <cstdio>
#include <bits/stdc++.h>

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
LinkedList* init() {
    LinkedList *head = new LinkedList;
    return head;
}

// 判断（入栈出栈）操作序列是否合法，以及确保终始状态为空栈
bool work3(char operate[]) {
    // 1. 定义cnt用于记录栈的长度，可用于判断链表是否为空以及出栈是否为合法操作
    int count = 0;
    int i = 0;
    // 2. 遍历操作序列，当为I时cnt++, 为O则cnt--
    while (operate[i] != '\0') {  // 达到字符末尾
        if (operate[i] == 'O') {
            // 非法操作序列
            if (count == 0) {
                return false;
            }
            count--;
        } else if (operate[i] == 'I') {
            count++;
        }
        i++;
    }
    // true 为空栈 false 不为空栈
    return count == 0;
}

// 判断单链表是否中心对称，如AXA 与 AXXA都是中心对称
bool work4(char arr[], int n) {
    LinkedList *head = init();
    // 1. 将n / 2个元素压入栈中
    for (int i = 0; i < n / 2; i++) {
        push(head, arr[i]);
    }
    // mid用于记录中心结点的后一个结点
    int mid = n / 2;
    // 奇数个时，进行加1
    if (n % 2 == 1) {
        mid++;
    }
    // 2. 将栈中元素依次取出，并与中心结点之后的结点进行比较
    for (int i = mid; i < n; i++) {
        LinkedList *node = pop(head);
        // 判断对称位置的结点数据是否相等
        if (node -> data != arr[i]) return false;
    }
    return true;
}

int main() {
    char A[] = {'I', 'I', 'O', 'O', 'I', 'I'};
//    printf("%d", work3(A));
    // work 4
    printf("%d", work4(A, 5));
    return 0;
}