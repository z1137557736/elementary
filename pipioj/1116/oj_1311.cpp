#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * 题意：本质上是删除无效括号，有两种case需要删除
 * 两个栈 一个存储无效左括号，一个存储无效右括号
 * case1: 右括号无法匹配对应的左括号，删除右括号
 * case2: 删除多余左括号
*/

int main() {
    string str;
    cin >> str;

    int i = 0;
    stack<int> s;   // 用于记录括号下标
    stack<int> s1;  // 记录待删除括号的下标
    for (char ch : str) {
        if (ch == '(') {
            s.push(i);
        } else {
            if (!s.empty()) {
                s.pop();
            } else {
                s1.push(i);     // 记录无效右括号的下标
            }
        }
        i++;
    }
    while (!s.empty()) {
        str.erase(s.top(), 1);      // 移除无效左括号
        s.pop();
    }
    while (!s1.empty()) {
        str.erase(s1.top(), 1);      // 逆序移除无效右括号
        s1.pop();
    }
    cout << str << endl;

    return 0;
}