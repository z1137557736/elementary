#include <cstdio>
#define MAX_SIZE 50
/**
 * 顺序表：线性表的顺序存储
 *
 * @author stan
 */

struct List {
    int data[MAX_SIZE];

    int length;
} sqList, sqList2, mergerList;

List initList(int pInt[10], int i);

/**
 * 在第i个位置上插入元素e，并将第i个元素及其后所有元素往后移一位
 * @param index 顺序表的位序
 * @param e 参数
 * @return
 */
bool insert(int index, int e) {
    // 1 <= index <= length (保证有效范围)
    if (index < 1 || index > sqList.length + 1) {
        return false;
    }
    // 超出最大容量
    if (index > MAX_SIZE) {
        return false;
    }
    for (int i = sqList.length; i >= index; i--) {
        // 后移一个元素
        sqList.data[i] = sqList.data[i - 1];
    }
    // 下标 = 次序 - 1
    sqList.data[index - 1] = e;
    sqList.length++;
    return true;
}

/**
 * 删除第i个位置的元素，并将i+1个元素及其后所有元素往前移一位
 * @param index 次序
 * @param e 返回元素
 * @return
 */
bool del(int index, int &e) {
    // 范围有效判断
    if (index < 1 || index > sqList.length) {
        return false;
    }
    e = sqList.data[index - 1];
    // 往前移动一位
    for (int i = index; i < sqList.length; i++) {
        sqList.data[index - 1] = sqList.data[index];
    }
    sqList.length--;
    return true;
}

/**
 * 按值查找第一个等于e的元素，并返回其次序
 * @param e
 * @return 次序
 */
int locate(int e) {
    for (int i = 1; i <= sqList.length; i++) {
        if (sqList.data[i] == e) {
            return i + 1;
        }
    }
    // 没找到返回-1
    return -1;
}

// 删除最小元素（假设唯一）
int delMin() {
    if (sqList.length == 0) {
        printf("system error");
        return -1;
    }
    // 最小值及其下标
    int min = sqList.data[0], k;
    for (int i = 2; i <= sqList.length; i++) {
        if (sqList.data[i - 1] < min) {
            // 记录最小值的下标
            k = i - 1;
            // 更新最小值
            min = sqList.data[i - 1];
        }
    }
    // 空出的位置由最后一位元素填补，长度减1
    sqList.data[k] = sqList.data[--sqList.length];
    return min;
}

// 删除顺序表中所有值为x的元素
void delX(int x) {
    // 用k来记录不等于x的元素的个数（也为新数组的下标）
    int k = 0;
    for (int i = 0; i < sqList.length; i++) {
        // 边扫描元素，边判断当前元素是否等于k
        if (sqList.data[i] != x) {
            // 将不等于x的元素排到第k个
            sqList.data[k] = sqList.data[i];
            // 下标加1
            k++;
        }
    }
    // 更新长度
    sqList.length = k;
}

// 从有序顺序表中删除定值s与t之间的所有元素
bool delRange(int s, int t) {
    if (s >= t) {
        printf("illegal parameter exception");
        return false;
    }
    if (sqList.length == 0) {
        printf("empty exception");
        return false;
    }
    // 记录有效值的个数
    int k  = 0;
    for (int i = 0; i < sqList.length; i++) {
        // remove value (s, t)
        if (sqList.data[i] <= s || sqList.data[i] >= t) {
            // 等同于只保留区间外的元素
            sqList.data[k] = sqList.data[i];
            k++;
        }
    }
    sqList.length = k;
    return true;
}

// 从有序顺序表中删除定值s与t之间的所有元素(包含s与t)
bool delRange2(int s, int t) {
    if (s >= t) {
        printf("illegal parameter exception");
        return false;
    }
    if (sqList.length == 0) {
        printf("empty exception");
        return false;
    }
    // 记录有效值的个数
    int k  = 0;
    for (int i = 0; i < sqList.length; i++) {
        // remove value [s, t]
        if (sqList.data[i] < s || sqList.data[i] > t) {
            // 等同于只保留区间外的元素
            sqList.data[k] = sqList.data[i];
            k++;
        }
    }
    sqList.length = k;
    return true;
}

// 从有序顺序表中移除重复值，应该注意到有序表中其重复值都是连续的
bool removeDuplicate() {
    if (sqList.length == 0) {
        return false;
    }
    // 有效值的个数，初始时将第一个元素视为非重复元素
    int k = 1;
    for (int i = 1; i < sqList.length; i++) {
        // 前后值不相同
        if (sqList.data[i - 1] != sqList.data[i]) {
            // 记录当前值
            sqList.data[k] = sqList.data[i];
            k++;
        }
    }
    // 更新数组长度
    sqList.length = k;
}

// 将两个有序顺序表合并为一个新的有序顺序表
void merge() {
    sqList2.data[0] = 1;
    sqList2.data[1] = 2;
    sqList2.data[2] = 4;
    sqList2.length = 3;
    if (sqList.length == 0) {
        mergerList = sqList2;
        return;
    }
    if (sqList2.length == 0) {
        mergerList = sqList;
        return;
    }
    // k j 分别对应两个有序顺序表的下标
    int k = 0, j = 0;
    // 合并数组的下标
    int i = 0;
    // 长度大于任意一个数组长度都退出循环
    while (k < sqList.length && j < sqList2.length) {
        if (sqList.data[k] < sqList2.data[j]) {
            mergerList.data[i] = sqList.data[k++];
        } else {
            mergerList.data[i] = sqList2.data[j++];
        }
        i++;
    }
    // 继续添加剩下的元素
    while (k < sqList.length) {
        mergerList.data[i++] = sqList.data[k++];
    }
    while (j < sqList2.length) {
        mergerList.data[i++] = sqList2.data[j++];
    }
    mergerList.length = i;
}

List initList(int data[10], int length) {
    List A;
    for (int i = 0; i < length; i++) {
        A.data[i] = data[i];
    }
    A.length = length;
    return A;
}

// 交换值
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// i为起始下标，len为长度
void reverse(List &A, int i, int len) {
    int j = len - 1;
    while (i <= len / 2) {
        swap(A.data[i++], A.data[j--]);
    }
}

// 将顺序表A与B位置转换，A={2, 3, 5, 8, 4, 7, 9},B={10, 15, 14}
// 算法思想：先将顺序表进行大转置，再将B与A再转置（大转置加小转置）
void swapLinearList() {
    int data[10] = {2, 3, 5, 8, 4, 7, 9, 10, 15, 14};
    List A = initList(data, 10);
    reverse(A, 0, 10);
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    reverse(A, 0, 3);
    printf("\n");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    reverse(A, 3, 10);
    printf("\n");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
}

// 逆置顺序表
void reverse() {
    for (int i = 1; i <= sqList.length / 2; i++) {
        // swap 交换法
        int temp = sqList.data[i - 1];
        sqList.data[i - 1] = sqList.data[sqList.length - i];
        sqList.data[sqList.length - i] = temp;
    }
}

void printList() {
    for (int i = 0; i < sqList.length; i++) {
        printf("%d ", sqList.data[i]);
    }
}

// 9. A的递增有序的顺序表，找出数值为x的元素，若找到，则将其与后继元素交换位置，若找不到，将其插入顺序表中
void locateEle(int e) {
    int data[10] = {2, 3, 4, 6, 7, 8, 9, 10, 13, 15};
    List A = initList(data, 10);
    int left = 0, right = A.length - 1;
    int index = -1;
    // 二分查找法
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A.data[mid] == e) {
            index = mid;
            break;
        } else if (A.data[mid] < e) {
            // 往右区间搜索
            left = mid + 1;
        } else {
            // 往左区间搜素
            right = mid - 1;
        }
    }
    // 若找到，则将其与后继元素交换位置
    if (index != -1) {
        // 最后一个元素无后继元素
        if (index != A.length - 1) {
            swap(A.data[index], A.data[index + 1]);
        }
    } else {
        int i;
        // 若找不到，将其插入顺序表中
        for (i = A.length - 1; i > right; i--) {
            // 右移元素
            A.data[i + 1] = A.data[i];
        }
        A.data[i + 1] = e;
        A.length++;
    }
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
}


// 11
int exam11(int A[], int B[], int n) {
    // 依次为A、B的首位数与末位数下标
    int al = 0, ar = n - 1, bl = 0, br = n - 1;
    while (al != ar || bl != br) {
        int mid1 = (ar + al) / 2;
        int mid2 = (br + bl) / 2;
        int a = A[mid1];
        int b = B[mid2];
        // 下面讨论三种情况
        if (a == b) {
            return a;
        } else if (a < b) {
            // 长度为奇数时，下标+1
            if ((ar - al) % 2 != 0) {
                al = mid1 + 1;
            } else {
                al = mid1;
            }
            br = mid2;
        } else {
            ar = mid1;
            // 长度为奇数时，下标-1
            if ((br - bl) % 2 != 0) {
                br = mid2 + 1;
            } else {
                br = mid2;
            }
        }
    }
    return A[al] < B[bl] ? A[al] : B[bl];
}

int main() {
    /*int e;
    del(2, e);
    printf("%d\n", e);
    printf("%d\n", locate(666));*/
    // printList();
    // delRange2(6, 9);
    // removeDuplicate();
    // locateEle(1);
    int A[] = {1, 2, 4};
    int B[] = {1, 3, 9};
    printf("%d", exam11(A, B, 3));
//    printList();
    //printf("min = %d", delMin());
    return 0;
}