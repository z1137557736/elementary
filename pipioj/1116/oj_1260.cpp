#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int i = 0;
    while (i + 1 < str.length()) {
        if (str[i] == str[i + 1]) {
            str.erase(i, 2);    // 删除相邻相同字母
            i = 0;              // 初始化i重新计算
        } else {
            i++;    //  不相同进行下一次匹配
        }
    }
    cout << str << endl;
    return 0;
}