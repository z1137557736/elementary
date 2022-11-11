

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
 * 核心: 相邻两个元素构成逆序，则进行交换, 外层循环每一次都能确定一个最大值
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

void bubble_sort2(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {  // 相邻元素，构成逆序，则交换元素
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
        printArr(arr, n);
    }
}

int main() {
    const int n = 10;
    int arr[n] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    printArr(arr, n);

    bubble_sort2(arr, n);

    return 0;
}