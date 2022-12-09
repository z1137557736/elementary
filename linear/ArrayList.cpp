#include <iostream>

using namespace std;

void reverse(int *arr, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        i++; j--;
    }
}

int main() {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    reverse(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}