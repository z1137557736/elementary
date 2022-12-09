#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> op_map;  // 定运算符的优先级

int main() {
    op_map['('] = 0;
    op_map['+'] = op_map['-'] = 1;
    op_map['/'] = op_map['*'] = 2;
    op_map['^'] = 3;

    string str;

    cin >> str;

    stack<char> ops;    // 创建运算符栈

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {   // 操作数直接输出
            cout << ch;
        } else {
            if (ch == '(') {    // 左括号特判
                ops.push(ch);
            } else if (ch == ')') { // 右括号特判
                while (ops.top() != '(') {
                    cout << ops.top(); ops.pop();   // 栈顶输出并出栈
                }
                ops.pop();  // 弹出左括号
            } else {
                while (!ops.empty() && op_map[ops.top()] >= op_map[ch]) {
                    cout << ops.top(); ops.pop();    // 栈顶输出并出栈
                }
                ops.push(ch);
            }
        }
    }

    // 操作
    while (!ops.empty()) {
        cout << ops.top(); ops.pop();
    }
    cout << endl;

    return 0;
}