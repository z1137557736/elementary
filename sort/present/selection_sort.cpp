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

int main() {
    const int n = 10;
    int arr[n];
    for (int i = 10; i > 0; i--) {
        arr[10 - i] = i;
    }
    printArr(arr, n);

    selectionSort(arr, n);

    return 0;
}