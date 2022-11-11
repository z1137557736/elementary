//
// Created by Stan on 2022/9/23.
//

#include <iostream>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

const int n = 10;

/**
 * 取较小者合并，追加，回写
 */
// 在[low, high]范围内进行排序, tmp为存放有序序列的辅助空间
void merge(int *arr, int *tmp, int low, int mid, int high) {
    int i = low, j = mid + 1;   // i和j分别为两个有序序列的起始地址
    int k = low;    // 辅助空间序列的起始地址
    while (i <= mid && j <= high) { // 合并两个有序序列
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];   // 总是取较小元素追加到到有序序列
        else tmp[k++] = arr[j++];
    }
    // 将剩余的元素追加到有序序列
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= high) tmp[k++] = arr[j++];
    // 将辅助空间的有序序列回写到待排序数组中
    for (int l = low; l <= high; l++) {
        arr[l] = tmp[l];
    }
}

int tmp[n]; // 辅助空间

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, tmp, low, mid, high);
        printArr(arr, n);
    }
}


int main() {
    int arr[n] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    merge_sort(arr, 0, 9);

    return 0;
}