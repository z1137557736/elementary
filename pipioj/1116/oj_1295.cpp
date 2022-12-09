#include <iostream>

using namespace std;

typedef struct LNode {
    int coef, expn; // 系数与指数
    LNode *next;
} *Polynomial;

Polynomial createP(int n) {
    Polynomial head, p;
    head = new LNode;
    head->next = nullptr;   // 创建带头结点
    for (int i = 0; i < n; i++) {   // 头插法
        p = new LNode;
        cin >> p->coef >> p->expn;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

Polynomial multi(Polynomial PA, Polynomial PB) {
    LNode *p1 = PA->next, *p2;   // p1为多项式A的工作指针
    Polynomial L = new LNode, pre;
    L->next = nullptr;  // L存储多项式乘积, pre指向第一个指数项小于等于p结点的前驱

    while (p1) {
        p2 = PB->next;    // p2为多项式B的工作指针
        while (p2) {
            LNode *p = new LNode;
            // 指数相加，系数相乘
            p->coef = p1->coef * p2->coef;
            p->expn = p1->expn + p2->expn;
            pre = L;    // 定位第一个指数项小于等于p结点的前驱
            while (pre->next && p->expn < pre->next->expn) {
                pre = pre->next;
            }
            // pre后继为空 或 p的指数大于pre后继的指数
            if (pre->next == nullptr || pre->next->expn < p->expn) {
                p->next = pre->next;
                pre->next = p;
            } else {
                // 若p的指数 等于 pre后继的指数
                int sum = pre->next->coef + p->coef;
                // 系数为0时，移除该指数项所对应的结点
                if (sum == 0) {
                    pre->next = pre->next->next;
                } else {    // 若系数不为0，累加系数
                    pre->next->coef += p->coef;
                }
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return L;
}

int main() {
    int n, m;
    cin >> n;
    Polynomial PA = createP(n);
    cin >> m;
    Polynomial PB = createP(m);
    Polynomial L = multi(PA, PB);

    LNode *p = L->next;
    while (p) {
        cout << p->coef << ' ' << p->expn << ' ';
        p = p->next;
    }
    cout << endl;
    return 0;
}