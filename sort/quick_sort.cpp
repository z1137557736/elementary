//
// Created by Stan on 2022/9/26.
//
#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int left, int right) {
    int pivot = left;
    int i = left + 1;

    for (int j = i; j <= right; j++) {
        if (arr[pivot] > arr[j]) {
            swap(arr[i++], arr[j]);
        }
    }

    swap(arr[i - 1], arr[pivot]);
    return i - 1;
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot);
        quick_sort(arr, pivot + 1, right);
    }
}

int main() {
    const int n = 8;
    int arr[n] = {20,7,35,17,66,25,3,27};

    quick_sort(arr, 0, 7);

    printArr(arr, n);
    return 0;
}