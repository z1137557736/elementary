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

void down_justify(int *arr, int curr, int len) {
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
}

/**
 * 构建大顶堆(完全二叉树，下标从1开始)，用于升序排序
 * 非叶子结点的个数为：向上取整[n/2], 叶子结点：向下取整[n/2]
 */
void build_heap(int *arr, int n) {
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
}

int main() {
    const int n = 10;
    int arr[n + 1] = {0, 85, 55, 82, 98, 68, 92, 99, 57, 66, 56};
    heap_sort(arr, n);
    return 0;
}
