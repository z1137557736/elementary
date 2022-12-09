#include <iostream>

using namespace std;

typedef struct LNode {
    int coef, expn; // 系数与指数
    LNode *next;
} *Polynomial;

Polynomial createP(int n) {
    Polynomial head, p, pre;
    head = new LNode; head -> next = nullptr;   // 带头结点
    for (int i = 0; i < n; i++) {
        pre = head; // pre指向第一个指数大于等于p的结点的前驱
        p = new LNode;
        cin >> p -> expn >> p -> coef;  // 输入指数与系数
        while (pre -> next && pre -> next -> expn < p -> expn) {
            pre = pre -> next;
        }
        // 若pre的后继为空 或 插入项的指数小于pre后继的指数
        if (pre -> next == nullptr || p -> expn < pre -> next -> expn) {
            p -> next = pre -> next;
            pre -> next = p;
        } else {
            // 插入项p的指数 等于 pre后继的指数
            int sum = pre -> next -> coef + p -> coef;  // 系数相加
            if (sum == 0) { // 系数和为0，remove pre的后继
                pre -> next = pre -> next -> next;
            } else {
                pre -> next -> coef = sum;  // 系数和不为0，合并同类项
            }
        }
    }
    return head;
}

Polynomial addP(Polynomial PA, Polynomial PB) {
    LNode *p1 = PA -> next, *p2 = PB -> next;   // p1 p2对应PA与PB的工作指针
    Polynomial L = PA, r = L;   // L为合并后的链表，r为其尾指针
    while(p1 && p2) {
        if (p1 -> expn == p2 -> expn) {
            int sum = p1 -> coef + p2 -> coef;
            if (sum != 0) {
                p1 -> coef = sum;   // 累加系数
                r -> next = p1; r = p1; // 保持r为尾指针
            }
            p1 = p1 -> next; p2 = p2 -> next;
        } else if (p1 -> expn < p2 -> expn) {  // 并入指数较小者
            r -> next = p1; r = p1; // 保持r为尾指针
            p1 = p1 -> next;
        } else {
            r -> next = p2; r = p2; // 保持r为尾指针
            p2 = p2 -> next;
        }
    }
    r -> next = p1 ? p1 : p2;   // 追加链表
    return L;
}

int main() {
    int n, m;
    cin >> n >> m;
    Polynomial PA = createP(n);
    Polynomial PB = createP(m);
    Polynomial L = addP(PA, PB);

    LNode *p = L -> next;
    while (p) {
        cout << p -> expn << ' ' << p -> coef << endl;
        p = p -> next;
    }
}