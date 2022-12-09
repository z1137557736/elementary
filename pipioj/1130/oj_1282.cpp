#include <iostream>

using namespace std;

int arr[10010], k;  // 第k大的元素

int partition(int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (high > low && arr[high] >= pivot) high--;
        arr[low] = arr[high];    // 比pivot小的值的放低端
        while (high > low && arr[low] <= pivot) low++;
        arr[high] = arr[low];    // 比pivot大的值放高端
    }
    arr[low] = pivot;   // 归位
    return low;
}

int quick_sort(int low, int high) {
    if (low < high) {
        int mid = partition(low, high);
        if (mid == k) return arr[mid];
        else if (k < mid) return quick_sort(low, mid - 1);
        return quick_sort(mid + 1, high);
    }
}

int main() {
    int n;
    cin >> n >> k;
    k = n - k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << quick_sort(0, n - 1) << endl;
}

