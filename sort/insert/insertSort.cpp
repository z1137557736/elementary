#include <cstdio>

/**
 * 直接插入排序(比较次数 n次、移动次数 n次,；边比较、边移动)
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(1)
 * 稳定性：稳定
 */
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int pre = i - 1;
        int current = arr[i];
        while (pre >= 0 && arr[pre] > current) {
            arr[pre + 1] = arr[pre];
            pre--;
        }
        arr[pre + 1] = current;
    }
}

/**
 * 折半(二分)插入排序(比较次数 log(n)次、移动次数 n次；将比较和移动分开操作)
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(1)
 * 稳定性：稳定
 */
void bInsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // 比较元素
        int current = arr[i];
        // up bound 返回第一个大于x的元素
        int left = 0, right = i;
        while (left < right) {
            int mid = (right + left) / 2;
            if (arr[mid] > current) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // 移动元素
        for (int k = i; k > left; k--) {
            arr[k] = arr[k - 1];
        }
        arr[left] = current;
    }
}

/**
 * 希尔排序本质上是对直接插入排序的一个优化
 * 由于直接插入排序在对有序度较高的数组进行排序时，效率较高
 * 所以希尔排序的核心思想是：基于增量对数组进行分组(组内)排序
 * 不妨设增量d: {4, 2, 1}
 * 时间复杂度: O(n^2)；一般情况下，比插入排序的效率要快
 * 空间复杂度: O(1)
 * 稳定性：不稳定
 */
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int current = arr[i];
            int pre = i - gap;
            while (pre >= 0 && arr[pre] > current) {
                arr[pre + gap] = arr[pre];
                pre -= gap;
            }
            arr[pre + gap] = current;
        }
    }
}

int main() {
    int A[] = {10, 1, 8, 7, 11, 2, 6, 5, 3};
    bInsertSort(A, 9);
    for (int i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}