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
 * 核心: 外层每次循环--在未排序的序列中找出最小（大）值，并在其（未排序的序列）起始位置的元素进行交换
 */
void selectionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        printArr(arr, n);
    }
}

void selection_sort2(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;  // j指向无序序列区的最小元素
        for (int k = i; k < n; k++) {
            if (arr[k] < arr[j]) j = k; // 保持j指向最小元素
        }
        int tmp = arr[i];   // 追加至有序序列区
        arr[i] = arr[j];
        arr[j] = tmp;
        printArr(arr, n);
    }
}

int main() {
    const int n = 10;
    int arr[n] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    printArr(arr, n);

    selection_sort2(arr, n);

    return 0;
}