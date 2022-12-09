#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    LNode *next;
} LNode, *List;

List createList(int *arr, int n) {
    List head, p, r;   // head为带头结点，p为工作指针, r为尾指针
    head = new LNode;
    head -> next = nullptr;
    r = head;
    for (int i = 0; i < n; i++) {
        p = new LNode;
        p -> data = arr[i]; p -> next = nullptr;
        r -> next = p;
        r = p;  // 尾插法
    }
    return head;
}

// 1267
void del_x(List head, int n, int k) {
    int num = 1, s = n - k + 1; // num记录结点个数，s指向倒数第k个结点
    LNode *p = head -> next, *pre = head;    // p 指向首元结点, pre 指向前驱结点
    while (p) {
        if (num == s) {
            // 删除p指针所指向的结点
            pre -> next = p -> next;
            delete p;
            break;  // 删除完毕，退出循环
        }
        num++;
        pre = p;    // 保持pre为前驱结点
        p = p -> next;
    }
}

void printNode(List head) {
    LNode *p = head -> next;
    while (p) {
        cout << p -> data << ' ';
        p = p -> next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    List head = createList(arr, n);
    del_x(head, n, k);

    printNode(head);

}