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

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
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

    insertionSort(arr, n);

    return 0;
}


