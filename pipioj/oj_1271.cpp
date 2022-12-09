#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    LNode *next;
} LNode, *List;

List createList(int *arr, int n) {
    List head, p, r;
    head = nullptr;
    for (int i = 0; i < n; i++) {
        p = new LNode;
        p -> data = arr[i];
        p -> next = nullptr;
        if (head == nullptr) {
            head = p;
            r = head;
        } else {
            r -> next = p;
            r = p;
        }
    }
    return head;
}

LNode *successor = nullptr; // 后继结点

List reverseN(List head, int n) {
    if (n == 1) {
        successor = head -> next;
        return head;
    }
    List last = reverseN(head -> next, n - 1);
    head -> next -> next = head;    // 反指
    head -> next = successor;       // 链住尾结点的后继结点
    return last;    // 返回头结点
}

// 区间范围内的反转链表
List reverseBetween(List head, int l, int m) {
    if (l == 1) {
        return reverseN(head, m);
    }
    head -> next = reverseBetween(head -> next, l - 1, m - 1);  // 链住头结点的前驱结点
    return head;
}

int main() {
    int n, l, m;
    cin >> n >> l >> m;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    List head = createList(arr, n);
    head = reverseBetween(head, l, m);

    LNode *p = head;
    while(p) {
        cout << p -> data << ' ';
        p = p -> next;
    }
    cout << endl;
}
