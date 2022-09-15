

//
// Created by Stan on 2022/9/14.
//

#include <iostream>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 核心: 相邻元素两两比较交换, 外层循环每一次都能确定一个最大值
 */
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            printArr(arr, n);
        }
        printf("\n");
    }
}

int main() {
    const int n = 10;
    int arr[n];
    for (int i = 10; i > 0; i--) {
        arr[10 - i] = i;
    }
    printArr(arr, n);

    bubbleSort(arr, n);

    return 0;
}