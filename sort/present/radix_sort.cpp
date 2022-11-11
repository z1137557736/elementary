//
// Created by Stan on 2022/11/1.
//

#include <iostream>
#include <vector>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

vector<int> buckets[10];   // 每个基数对应一个桶，用于存放分配时的数据

// 获取整数长度
int get_length(int n) {
    int d = 0;
    while (n > 0) {
        n /= 10;
        d++;
    }
    return d;
}

// 取关键字的最大位数
int get_bit(int *arr, int n) {
    int d = 0;
    int max = arr[0];
    // 取最大值
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return get_length(max);
}

// 获取num的第k位数, 超出则返回0
int get_index(int num, int k) {
    int idx = 0;
    for (int i = 0; i < k; i++) {
        idx = num % 10; // 取num的最低位数
        num /= 10;  // 舍弃num的最低位
    }
    return idx;
}


// 实现基数排序
void radix_sort(int *arr, int n) {
    // 1. 取关键字最大个数
    int bit = get_bit(arr, n);
    // 执行d次的分配与收集
    for (int d = 1; d <= bit; d++) {
        // 2. 分配 - 每一趟分配需要执行n次
        for (int i = 0; i < n; i++) {
            int k = get_index(arr[i], d);   // 获取整数的第d位
            buckets[k].push_back(arr[i]);
        }
        int k = 0;  // 用于收集数据的工作指针，每次从0开始
        // 3. 收集 - 每一趟收集需要执行rd次 [0, 9]
        for (int i = 0; i < 10; i++) {
            // 将桶中数据收集到原序列区
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[k++] = buckets[i][j];
            }
            buckets[i].clear();  // 收集完毕后清空当前第i个基数的桶
        }
        printArr(arr, n);
    }
}

const int n = 8;

int main() {
    int arr[n] = {23, 1, 4, 9, 98, 132, 42, 211};

    printArr(arr, n);

    radix_sort(arr, n);
    return 0;
}