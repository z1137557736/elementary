#include <iostream>

using namespace std;


// 迭代实现
int lastRemaining(int n, int m) {
    // 幸存者在n-1轮杀人游戏后的位置
    int x = 0;  // 当区间长度为1时，即为最后一个幸存者
    for (int i = 2; i <= n; i++) {
        x = (x + m) % i;    // f(i) = (f(i - 1) + m)*i;  i为区间长度 - 进行区间复现，定位幸存者在原循环链表中的位置
    }
    return x;
}


int main() {
    int n, m;
    cin >> n >> m;
    cout << lastRemaining(n, m) + 1 << endl;
    return 0;
}