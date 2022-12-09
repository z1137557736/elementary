#include <iostream>

using namespace std;

int A[100001], B[100001], C[100001];

int max(int a, int b) {
    return a > b ? a : b;
}

void intersection(int n, int m, int q) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < q) {
        if (A[i] == B[j] && B[j] == C[k]) {
            cout << A[i] << ' ';
            i++; j++; k++;
        } else {
            int num = max(max(A[i], B[j]), C[k]);    // 取三者最大值
            if (A[i] < num) i++;
            if (B[j] < num) j++;
            if (C[k] < num) k++;
        }
    }
    cout << endl;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> C[i];
    }
    intersection(n, m, q);
}