//
// Created by Stan on 2022/9/23.
//

#include <iostream>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeSort(int *arr, int *temp, int lf, int ll, int rf, int rl) {
    int k = 0, i = lf, j = rf;
    while (i <= ll && j <= rl) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= ll) {
        temp[k++] = arr[i++];
    }

    while (j <= rl) {
        temp[k++] = arr[j++];
    }

    // 写入 ARR
    for (i = 0; i < k; i++) {
        arr[lf + i] = temp[i];
    }
    // 写入 arr
    /*for (int u = rl; u >= lf; u--) {
        arr[u] = temp[k--];
    }*/

}

//  10 0 9
//  5 0 4
//  2 0 1
//  1 0 1
void merge(int *arr, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        int temp[last + 1];
        //  5 0 4
        //  2 0 1
        //  1 0 1
        //  0 0 -1
        merge(arr, first, mid);
        //  5 5 9
        //  2 2 4
        merge(arr, mid + 1, last);
        mergeSort(arr, temp, first, mid, mid + 1, last);
    }
}

int main() {
    const int n = 10;
    int arr[n] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};

    merge(arr, 0, 9);

    printArr(arr, n);

    return 0;
}