//
// Created by Liu Xu on 2021/8/26.
//

#include <cstdio>

/**
 * 选择排序
 * 时间复杂度: O(n^2) 不管待排序数组是否有序，其时间复杂度总是为O(n^2)
 * 空间复杂度: O(1)
 * 稳定性：不稳定（数组内部交换元素）
 */
void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

/**
 * 选择排序的处理过程
 * 4, 7, 6, 5, 3, 2, 8, 1
 * 1, 7, 6, 5, 3, 2, 8, 4
 * 1, 2, 6, 5, 3, 7, 8, 4
 * 1, 2, 3, 5, 6, 7, 8, 4
 * 1, 2, 3, 4, 6, 7, 8, 5
 * 1, 2, 3, 4, 5, 7, 8, 6
 * 1, 2, 3, 4, 5, 6, 8, 7
 * 1, 2, 3, 4, 5, 6, 7, 8
 */
int main() {
    int arr[] = {4, 7, 6, 5, 3, 2, 8, 1};
    selectSort(arr, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
