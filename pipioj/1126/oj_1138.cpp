#include <iostream>

using namespace std;

/**
 * <h2>N皇后</h2>
 * 所谓N皇后，即N个皇后在N*N的棋盘上在互相不能攻击的情况下有几种摆放方案<br/>
 * 如何判定互相不能攻击，即如何判定是否在同一行、同一列、或同一对角线呢？<br/>
 * 答：按行遍历，并加一个当前列的访问标记，皇后必不会在同一行或同一列，这样行和列解决了。<br/>
 * 观察可知，同一个主对角线上的元素，其行列坐标之 差 相等。同一个副对角线上的元素，其行列坐标之 和 相等。<br/>
 * 因此，只需一个一维数组，即可标记当前对角线的可达状态。
 * e.g. 主对角线dia_l[0] = 1, 即(0,0), (1,1), (2,2)都表明不可达
*/
int ans = 0, n;
bool vis_col[50] = {false},    // 标记列的可达状态
vis_l[50] = {false},      // 标记主对角线元素的可达状态
vis_r[50] = {false};      // 标记副对角线元素的可达状态

// 时间复杂度为O(n!) why? 对于第一个皇后有n种选择，第二个皇后有n-1种选择，第三个皇后有n-2种选择...
void queenN(int row) {
    if (row == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {   // 枚举1～n的所有摆放位置
        int l = row - i + n;    // 加n保证l为正数
        int r = row + i;
        // 判定当前位置是否可摆放皇后
        if (!vis_col[i] && !vis_l[l] && !vis_r[r]) {
            vis_col[i] = vis_l[l] = vis_r[r] = true;   // 标记为不可达
            queenN(row + 1);
            vis_col[i] = vis_l[l] = vis_r[r] = false;   // 标记为可达，由于是枚举，需擦除痕迹
        }
    }
}

int main() {
    cin >> n;
    queenN(0);
    cout << ans << endl;
}