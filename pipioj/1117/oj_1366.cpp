#include <iostream>

using namespace std;

const int MAX_SIZE = 111;   // 字符串的最大长度

int _next[MAX_SIZE]; // next数组

void get_next(string T) {   // 生成next数组
    int i = 0, j = -1;
    _next[0] = -1;
    while (i < T.length()) {
        if (j == -1 || T[i] == T[j]) {
            i++; j++;
            _next[i] = j;
        } else {
            j = _next[j];
        }
    }
    for (int k = 0; k < T.length(); k++) {
        cout << _next[k] + 1 << ' ';
    }
    cout << endl;
}

int KMP(string S, string T) {
    int i = 0, j = 0, tlen = T.length();
    while (i < S.length() && j < tlen) {
        if (j == -1 || S[i] == T[j]) {
            i++; j++;
        } else {
            j = _next[j];    // 主串不回溯，子串基于next数组重新定位匹配
        }
    }
    if (j >= tlen) {
        return i - j;   // 匹配成功，返回模式串在主串出现的位置
    } else {
        return -1;
    }
}


int main() {
    string S, T;
    while (cin >> S >> T) {
        get_next(T);
        int idx = KMP(S, T);
        cout << idx + 1 << endl;
    }
}