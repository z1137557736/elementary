#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        bool flag = true;
        stack<char> S;
        for (char i : str) {
            if (i == '(' || i == '[' || i == '{') {
                S.push(i);
            } else if (!S.empty()) {
                if ((i == ')' && S.top() == '(')
                    || (i == ']' && S.top() == '[')
                    || (i == '}' && S.top() == '{')) {
                    S.pop();
                } else {
                    flag = false;
                    break;
                }
            } else {
                flag = false;
                break;
            }
        }
        if (flag && S.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}