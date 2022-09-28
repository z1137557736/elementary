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

int main() {
    const int n = 10;
    int arr[n] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};

    shellSort(arr, n);
    return 0;
}
