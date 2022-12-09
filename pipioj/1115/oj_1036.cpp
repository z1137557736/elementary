#include <string>
#include <iostream>
#include <utility>
#include <stack>

using namespace std;


int main() {
    string str;
    while (cin >> str) {
        stack<int> S1;  // 用于匹配括号的栈
        stack<pair<int, int>> S2;   // 用于输出每队括号下标的栈
        int i = 1;
        for (char ch : str) {
            if (ch == '(') {
                S1.push(i++);
            } else {
                int f = S1.top(); S1.pop();
                pair<int, int> p(f, i++);
                S2.push(p);
            }
            if (S1.empty()) {   // 实现括号下标顺序输出
                while(!S2.empty()) {
                    pair<int, int> p = S2.top(); S2.pop();
                    cout << p.first << ' ' << p.second << endl;
                }
            }
        }
    }
    return 0;
}