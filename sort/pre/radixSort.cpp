//
// Created by Liu Xu on 2021/9/6.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> ve[10];

// 获取最大位数
int getMaxDigit(int arr[], int n) {
    int maxV = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxV) {
            maxV = arr[i];
        }
    }
    int maxDigit = 0;
    while (maxV > 0) {
        maxV /= 10;
        maxDigit++;
    }
    return maxDigit;
}

/**
 * 归并排序(将数组分为两份，并逐步从两段数据中挑选出最小元素加入到新数组中)
 * 时间复杂度: O(n * k)
 * 空间复杂度: O(n + k)
 * 稳定性：稳定
 */
void radixSort(int arr[], int n, int maxDigit) {
    int radix = 1;
    for (int i = 0; i < maxDigit; i++, radix *= 10) {
        for (int j = 0; j < n; j++) {
            int index = (arr[j] / radix) % 10;
            ve[index].push_back(arr[j]);
        }
        int idx = 0;
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < ve[k].size(); j++) {
                arr[idx] = ve[k][j];
                idx++;
            }
            ve[k].clear();
        }
    }
}

int main() {
    int A[8] = {3, 42, 38, 98, 101, 5, 7, 20};
    radixSort(A, 8, getMaxDigit(A, 8));
    for (int i = 0; i < 8; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}