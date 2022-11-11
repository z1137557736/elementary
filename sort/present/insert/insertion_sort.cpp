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

void insert_sort2(int *arr, int n) {
    for (int i = 1; i < n; i++) {   // 从第二个元素进行插入排序
        int j = i, curr = arr[i];   // j为待插入元素的位置
        while (j > 0 && arr[j - 1] > curr) {  // 若构成逆序，则交换元素数据
            arr[j] = arr[j - 1];    // 右移元素，给待插入元素腾出位置
            j--;
        }
        arr[j] = curr;  // 插入元素
    }
}

int main() {
    const int n = 10;
    int arr[n] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    printArr(arr, n);

    insert_sort2(arr, n);

    printArr(arr, n);



    return 0;
}


