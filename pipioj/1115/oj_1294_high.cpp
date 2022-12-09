#include <iostream>
#include <map>

using namespace std;

/**
 * A+B for Polynomials
 * 题意：关于多项式加法
 */

int n;
// 存放多项式结果
map<int, int> mp;

int main() {
    // 多项式的项数 | 指数
    int n, m, expo;
    // 系数
    int coef;
    // 读取多项式A的项数
    cin >> n >> m;
    // 多项式相加，指数相同的项进行系数相加
    while (n--) {
        scanf("%d %d", &expo, &coef);
        mp[expo] = coef;
    }
    while (m--) {
        scanf("%d %d", &expo, &coef);
        // 指数相同，合并同类项
        if (mp[expo]) {
            mp[expo] += coef;
        } else {
            mp[expo] = coef;
        }
    }
    // 删除系数为0的多项式
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it -> second == 0) {
            mp.erase(it);
        }
    }
    // map本身是字典序，如果从大到小遍历，需要倒着遍历
    for (auto it = mp.begin(); it != mp.end(); it++) {
        printf("%d %d\n", it -> first, it -> second);
    }
    return 0;
}