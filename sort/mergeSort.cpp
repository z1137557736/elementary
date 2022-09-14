//
// Created by Liu Xu on 2021/9/3.
//
#include <cstdio>

/**
 * 归并排序(将数组分为两份，并逐步从两段数据中挑选出最小元素加入到新数组中)
 * 时间复杂度: O(n logn)
 * 空间复杂度: O(n)
 * 稳定性：稳定
 */
void mergeSort(int arr[], int temp[], int L1, int R1, int L2, int R2) {
    int k = 0, i = L1, j = L2;
    while (i <= R1 && j <= R2) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= R1) {
        temp[k++] = arr[i++];
    }
    while (j <= R2) {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < k; i++) {
        arr[L1 + i] = temp[i];
    }
}

void merge(int arr[], int left, int right) {
    if (left < right) {
        int temp[right + 1];
        int mid = (left + right) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);
        mergeSort(arr, temp, left, mid, mid + 1, right);
    }
}
int main() {
    int A[8] = {4, 7, 6, 5, 3, 2, 8, 1};
    merge(A, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}