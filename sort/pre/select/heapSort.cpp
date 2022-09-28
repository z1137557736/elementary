/**
 * 构建大顶堆，其中完全二叉树采用数组存储，且首元素从下标1开始
 * 含：创建、插入、删除、堆排序四种操作
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 2 << 4;
int heap[MAX_SIZE] = {};
// 数组长度
int n;

/**
 * 构建小顶堆时，用到向下调整
 * @param parentIndex 待调整父结点
 * @param length 数组长度
 * @return
 */
int downAdjust(int parentIndex, int length) {
    // child 指向父结点的左孩子
    int child = parentIndex * 2;
    while (child <= length) {
        // 若右孩子存在 && 右孩子 大于 左孩子
        if (child + 1 <= length && heap[child + 1] > heap[child]) {
            // child 指向父结点的右孩子
            child += 1;
        }
        if (heap[child] > heap[parentIndex]) {
            swap(heap[child], heap[parentIndex]);
            // 父结点指向子结点
            parentIndex = child;
            // child 再次指向左孩子
            child = child * 2;
        } else {
            break;
        }
    }
}

/**
 * 插入结点时，用到向上调整
 * @param index
 */
void upAdjust(int index) {
    int parentIndex = index / 2;
    while (parentIndex >= 1) {
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            // 继续往上找父结点
            parentIndex = parentIndex / 2;
        } else {
            break;
        }
    }
}

// 构建大顶堆
void createHeap() {
    // 从最后一个非叶子结点开始向下调整
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

// 插入结点
void insert(int x) {
    heap[++n] = x;
    // 进行向上调整
    upAdjust(n);
}

// 删除堆顶元素
void deleteTop() {
    // 用尾元素替换堆顶元素
    heap[1] = heap[n--];
    downAdjust(1, n);
}

/**
 * 堆排序
 * 时间复杂度: O(nlogn) 不管待排序数组是否有序，其时间复杂度总是为O(nlogn)
 * 空间复杂度: O(1)
 * 稳定性：不稳定（数组内部交换元素）
 *
 */
void heapSort() {
    int k = n;
    for (int i = 1; i <= n; i++) {
        // 交换首尾值
        swap(heap[1], heap[k--]);
        // 堆顶元素进行向下调整
        downAdjust(1, k);
    }
}

// 9 7 1 3 10 5 2 8 9 6
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
    }
    createHeap();
    insert(0);
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    heapSort();
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    /*deleteTop();
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");*/
}