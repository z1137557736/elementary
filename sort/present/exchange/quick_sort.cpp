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

void swap2(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int *arr, int left, int right) {
    int pivot = left;
    int i = left + 1;

    for (int j = i; j <= right; j++) {
        if (arr[pivot] > arr[j]) {
            swap2(arr[i++], arr[j]);
        }
    }

    swap2(arr[i - 1], arr[pivot]);
    return i - 1;
}

/**
 * 算法步骤
 * 1. 取low号为pivot
 * 2. 从high位开始，将比pivot小的元素移到低位（low位与high位元素交换）
 * 3. 从low位开始，将比pivot大的元素移到高位（low位与high位元素交换）
 * 4. 回写pivot并返回low(之前并未swap，而是覆盖pivot)
 */
int partition2(int *arr, int low, int high) {   // low为待交换的低端元素，high为待交换的高端元素
    int pivot = arr[low];   // 0号位做为pivot
    while (low < high) {
        while(low < high && arr[high] >= pivot) high--;
        //swap2(arr[low], arr[high]);
        arr[low] = arr[high];   // 将比pivot小的值移到低端
        while (low < high && arr[low] <= pivot) low++;
        //swap2(arr[low], arr[high]);
        arr[high] = arr[low];   // 将比pivot大的值移到高端
    }
    arr[low] = pivot;
    return low;
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition2(arr, left, right);
        printArr(arr, 10);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

int main() {
    const int n = 10;
    int arr[n] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    quick_sort(arr, 0, 9);


    return 0;
}