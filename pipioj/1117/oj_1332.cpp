#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        stack<int> s;   // 记录括号下标
        int k = 0;  // 括号下标
        for (char ch: str) {
            if (ch == '(') {
                s.push(k);
            } else if (ch == ')') { // 若为右括号
                reverse(str.begin() + s.top(), str.begin() + k);   // 反转括号内的字符
                s.pop();
            }
            k++;
        }
        for (char ch: str) {
            if (ch != '(' && ch != ')') cout << ch;
        }
        cout << endl;
    }
    return 0;
}