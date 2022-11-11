//
// Created by Stan on 2022/9/22.
//

#include <iostream>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 稳定性：不稳定, 第一次循环时，会被分为 gap = len / 2，类似快排，因而不稳定
 */
void shellSort(int *arr, int n) {
    for (int gap = n >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < n; i++) {
            int j = i;
            while (j - gap >= 0 && arr[j - gap] > arr[j]) {
                swap(arr[j - gap], arr[j]);
                j -= gap;
            }
        }
        printArr(arr, n);
    }
}

void shellSort2(int *arr, int n) {
    // gap 为增量
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;   // j为工作指针
            while (j - gap >= 0 && arr[j - gap] > arr[j]) { // 从后向前比较，若构成逆序，则进行元素交换
                swap(arr[j], arr[j - gap]); // 交换元素
                j -= gap;   // 减去增量，继续比较
            }
        }
        printArr(arr, n);
    }
}

int gaps[3] = {5, 3 ,1};    // 定义增量

void shell_sort3(int *arr, int n) {
    for (int k = 0; k < 3; k++) {
        for (int i = gaps[k]; i < n; i++) {
            int j = i, curr = arr[i];   // j为待插入元素的位置
            while(j - gaps[k] >= 0 && arr[j - gaps[k]] > curr) {    // 构成逆序
                arr[j] = arr[j - gaps[k]];  // 右移元素，给待插入元素腾出位置
                j = j - gaps[k];
            }
            arr[j] = curr;  // 插入元素
        }
        printArr(arr, n);
    }
}

int main() {
    const int n = 10;
    int arr[n] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    // // shellSort(arr, n);
    printf("\n");
    shell_sort3(arr, n);

    return 0;
}
