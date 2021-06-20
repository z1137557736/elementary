#include <cstdio>
#include <string>

using namespace std;

/**
 * 方法一
 * 根据前一个next值求解后一个next值(next[0] = -1)
**/

/**
 * 1: 初始化next[], 且next[0] = -1(因为一个字符无法构成前后缀)
 * 2: 令i在 1 ～ s.len 之间进行遍历，j = next[i - 1], 并循环执行第3, 4步
 * 3: 若s[i] == s[j + 1], 则next[i] = j + 1
 * 4: 若j != -1 && s[i] != s[j + 1], 则反复令j = 上一个子串的最长相等前后缀的前缀的最后一个元素的下标
 */
void getNext(string s, int next[]) {
    // 第一个子串总是为-1
    next[0] = -1;
    int j = next[0];
    for (int i = 1; i < s.length(); i++) {
        while (j != -1 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        // 记录子串S[0, i]的最长相等前后缀的前缀的最后一个元素的下标
        next[i] = j;
    }
}

// 优化后的next，记为nextval
void getNextVal(string s, int next[]) {
    // 第一个子串总是为-1
    next[0] = -1;
    int j = next[0];
    for (int i = 1; i < s.length(); i++) {
        while (j != -1 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        // note: 只有这里发生变化

        // 为什么这里不判断 i + 1 < len? 因为s[len] == '\0'，且next[len - 1]本身无意义，不会被用到
        if (j == -1 || s[i + 1] != s[j + 1]) {
            next[i] = j;
        } else {
            // 继承上一个双胞胎子串的next
            next[i] = next[j];
        }

    }
}

/**
 * 1. 初始化j = -1，标识j为已匹配子串的最后一个元素的下标
 * 2. 令i在 0 ~ text.len 之间进行遍历，并循环执行第3、4步
 * 3. 若 j != -1 && text[i] != patter[j + 1], 则反复令j = next[j]
 * 4. 若 text[i] == patter[j + 1], 则令j++
 * @param text 字符串
 * @param pattern 匹配串
 * @return text中是否有pattern
 */
bool KMP(string text, string pattern) {
    int next[pattern.length()];
    getNextVal(pattern, next);
    int j = -1;
    for (int i = 0; i < text.length(); i++) {
        while (j != -1 && text[i] != pattern[j + 1]) {
            j = next[j];
        }
        if (text[i] == pattern[j + 1]) {
            j++;
        }
        if (j == pattern.length() - 1) {
            return true;
        }
    }
    return false;
}

/**
 * 方法二
 * 根据最大公共元素长度求next
**/

void getNext2(string s, int next[]) {
    int i, j;
    next[0] = -1;
    i = 0; j = -1;
    while (i < s.length()) {
        if (j == -1 || s[i] == s[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else{
            j = next[j];
        }
    }
}

bool KMP2(string text, string pattern) {
    int i = 0, j = 0;
    int next[pattern.length()];
    getNext2(pattern, next);
    while (i < text.length()) {
        if (j == 0 || text[i] == pattern[j]) {
            i++; j++;
        } else {
            j = next[j];
        }
        if (j == pattern.length() - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("%d\n", KMP("abababa", "ababab"));
    printf("%d\n", KMP2("abababa", "abcac"));
    return 1;
}