#include <cstdio>
#include <stack>
#define MAX_SIZE 20

double pn[MAX_SIZE];   // P(n, x)对应n的值

using namespace std;

stack<char> s;

// 判断括号是否配对
bool work1(char C[]) {
    int i = 0;
    while (C[i] != '\0') {
        if (C[i] == '{' || C[i] == '[' || C[i] == '(') {
            s.push(C[i]);
        }
        // 判断左右括号是否相等
        switch (C[i]) {
            case '}':
                if (s.top() == '{') s.pop(); break;
            case ']':
                if (s.top() == '[') s.pop(); break;
            case ')':
                if (s.top() == '(') s.pop(); break;
        }
        i++;
    }
    return s.empty();
}

// work3 打表法
double P(int n, double x) {
    // 初始化值
    double r1 = 1, r2 = 2 * x;
    if (n == 0) return r1;
    if (n == 1) return r2;
    pn[0] = r1;
    pn[1] = r2;
    int i = 2;
    // 自底向上的思路
    while (i <= n) {
        double r3 = 0;
        r3 = r2 * pn[i - 1] + 2 * (i - 1) * pn[i - 2];
        // 更新对应n的值
        pn[i] = r3;
        i++;
    }
    return pn[n];
}



int main() {
    char C[] ={'{', '(', '[', ']', '[', ']', ')', '}'};
    // printf("%d", work1(C));
    printf("%lf", P(3, 1));
    return 0;
}