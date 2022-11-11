//
// Created by Stan on 2022/9/28.
//

#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*void down_justify(int *arr, int curr, int len) {
    // 最大孩子结点
    int child = curr * 2;
    if (child + 1 > len) {
        return;
    }
    // 左右孩子结点比较大小, 确定最大孩子结点
    if (arr[child] < arr[child + 1]) {
        child = child + 1;
    }
    if (arr[curr] < arr[child]) {
        swap(arr[curr], arr[child]);
        down_justify(arr, child, len);
    }
}*/
// 对堆在[low, high]范围内进行调整
void down_justify(int *arr, int low, int high) {
    int i = low, j = low * 2;    // i为待调整结点, j为其的左孩子
    while (j <= high) {  // 如果左孩子存在
        if (j + 1 <= high && arr[j + 1] > arr[j]) {  // 若右孩子存在且值大于左孩子
            j = j + 1;  // 更新为右孩子
        }
        if (arr[i] < arr[j]) {  // 孩子的值大于待调整结点i的值
            swap(arr[i], arr[j]);   // 交换两者的值
            i = j;  // 保持i为待调整结点
            j = j * 2;  // 保持j为待调整结点的孩子
        } else {
            break;  // 孩子值小于待调整结点i的值，此时无需调整，退出操作
        }
    }
}

// 构建堆
void build_heap(int *arr, int n) {
    // 完全二叉树的非叶子结点范围[1,n/2]，对非叶子结点进行向下调整
    for (int i = n / 2; i > 0; i--) {
        down_justify(arr, i, n);
    }
}

// 堆排序
void heap_sort(int *arr, int n) {
    build_heap(arr, n);
    printArr(arr, n);
    for (int i = 0; i < n; i++) {
        // 首尾交换
        swap(arr[1], arr[n - i]);
        down_justify(arr, 1, n - i - 1);
    }
    printArr(arr, n);
}

/**
 * 构建大顶堆(完全二叉树，下标从1开始)，用于升序排序
 * 非叶子结点的个数为：向上取整[n/2], 叶子结点：向上取整[n/2] + 1
 */
/*void build_heap(int *arr, int n) {
    for (int i = n / 2; i > 0; i--) {
        down_justify(arr, i, n);
    }
}

void heap_sort(int *arr, int n) {
    build_heap(arr, n);
    int k = n;
    for (int i = 1; i <= n; i++) {
        swap(arr[1], arr[k--]);
        // 大顶堆 - 利用 "向下调整后，其堆首元素为最大值"的思想
        down_justify(arr, 1, k);
    }
    printArr(arr, n);
}*/

int main() {
    const int n = 10;
    int arr[n + 1] = {0, 85, 55, 82, 98, 68, 92, 99, 57, 66, 56};
    heap_sort(arr, n);
    return 0;
}
