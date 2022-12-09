#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

// 1. 中缀转后缀
// 2. 后缀表达式的计算
struct Node {
    int num;    // 操作数
    char op;     // 运算符
    bool flag;   // true 为操作数 - false 为运算符
};

map<char, int> op_map;    // 定义运算符的优先级

int main() {
    string str;
    op_map['('] = 0;
    op_map['-'] = op_map['+'] = 1;
    op_map['*'] = op_map['/'] = 2;
    while (cin >> str) {
        vector<Node> RPN;  // 存放后缀表达式 - 逆波兰表达式
        stack<Node> ops;    // 运算符栈

        /* 中缀转后缀 */
        for (int i = 0; i < str.length();) {    // 存在多位数，手动i++
            Node p;
            if (str[i] >= '0' && str[i] <= '9') {   // 数值直接加入到后缀表达式
                int num = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    num *= 10;
                    num += str[i++] - '0';
                }
                p.num = num;
                p.flag = true;
                RPN.push_back(p);
            } else {
                p.op = str[i++];
                p.flag = false;
                // 栈顶元素的优先级大于op，将其加入到后缀表达式
                while (!ops.empty() && op_map[ops.top().op] >= op_map[p.op]) {
                    RPN.push_back(ops.top());
                    ops.pop();  // 栈顶元素出栈
                }
                // 运算符栈为空或 op的优先级大于栈顶元素
                ops.push(p);
            }
        }
        // 将运算符栈中的剩余元素加入到后缀表达式中
        while (!ops.empty()) {
            RPN.push_back(ops.top());
            ops.pop();  // 栈顶元素出栈
        }

        /* 后缀表达式的计算 */
        stack<int> nums;    // 操作数栈
        for (int i = 0; i < RPN.size(); i++) {
            Node p = RPN[i];
            if (p.flag) {   // 若为操作数, 直接入栈
                nums.push(p.num);
            } else {
                // 若为运算符，弹出两个数值进行计算
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                int ans;
                switch (p.op) {
                    case '+': ans = a + b; break;
                    case '-': ans = a - b; break;
                    case '*': ans = a * b; break;
                    case '/': ans = a / b; break;
                }
                nums.push(ans);
            }
        }
        cout << nums.top() << endl;
    }
}