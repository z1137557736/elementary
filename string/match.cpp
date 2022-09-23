#include <iostream>
#include <string>

using namespace std;

/**
 * 暴力匹配模式
 * 时间复杂度O(n*m) n 为主串, m为子串
 */
bool match(string &text, string &keyWord) {
    int n = text.length();
    int m = keyWord.length();
    int i = 0,j = 0;
    while (i < n && j < m) {
        if (text[i] == keyWord[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    printf("i: %d j: %d\n", i, j);
    return j == m;
}

int main() {
    string text = "abceabcde";
    string keyWord = "abcd";
    printf("%d\n", match(text, keyWord));
    return 0;
}