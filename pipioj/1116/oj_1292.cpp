#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int>  op_map; // 定义运算符的优先级

int main() {
    op_map['+'] = op_map['-'] = 1;
    op_map['*'] = op_map['/'] = 2;
    op_map['^'] = 3;
    string str;
    cin >> str;
    stack<char> ops; // 定义运算符栈
    vector<char> RPN;   // 存放后缀表达式
    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            RPN.push_back(ch);
            cout << ch; // 作为后缀表达式，直接输出
        } else {
            while (!ops.empty() && op_map[ops.top()] >= op_map[ch]) {
                cout << ops.top();
                RPN.push_back(ops.top());
                ops.pop();
            }

            // 操作符入栈
            ops.push(ch);
        }
    }
    while (!ops.empty()) {
        cout << ops.top();
        RPN.push_back(ops.top());
        ops.pop();
    }
    cout << endl;
    return 0;
}