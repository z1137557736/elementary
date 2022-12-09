#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        stack<int> s;
        int mod = 0;  // 记录栈的变化次数
        for (char ch : str) {
            if (ch == '(') {
                s.push(mod++);
            } else {
                int left = s.top();
                s.pop();
                if (s.empty()) {
                    for (int i = left + 1; i < mod; i++) {
                        cout << str[i];
                    }
                }
                mod++;
            }
        }
        cout << endl;
    }
    return 0;
}