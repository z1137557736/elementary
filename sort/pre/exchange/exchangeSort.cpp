//
// Created by Liu Xu on 2021/8/25.
//

#include <cstdio>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 冒泡排序(相邻两两元素进行比较)
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(1)
 * 稳定性：稳定
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * 分区的两种方法：
 * 1.填坑法(ky中快速排序分区的方法)
 * 2.指针交换法
 * 3.双指针前移法
 */
int partition(int arr[], int left, int right) {
    // 采用第一个元素作为基准
    int pivot = arr[left];
    while (left < right) {
        while (left < right && pivot < arr[right]) {
            right--;
        }
        // 填坑
        arr[left] = arr[right];
        while (left < right && pivot > arr[left]) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

/**
 * 快速排序(基于分区、分治的思想)
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(logn)
 * 稳定性：不稳定
 */
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

/**
 * lchild rchild arr
 *  0     7    1 7 6 5 3 2 8 1
 *  1     6    1 7 6 5 3 2 8 7
 *  1     5    1 2 6 5 3 2 8 7
 *  2     5    1 2 6 5 3 6 8 7
 *  2     4    1 2 3 5 3 6 8 7
 *  3     4    1 2 3 5 5 6 8 7
 *  3     3    1 2 3 4 5 6 8 7
 */
int main() {
    int A[] = {4, 7, 6, 5, 3, 2, 8, 1};
    quickSort(A, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

