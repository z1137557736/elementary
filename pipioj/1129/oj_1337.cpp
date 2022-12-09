#include <iostream>

using namespace std;

void move(int i, char A, char B) {
    printf("Move disk %d from %c to %c\n", i, A, B);
}

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {   // 只有一个盘子，直接将盘子从A移到C
        move(n, A, C);
        return;
    }
    hanoi(n - 1, A, C, B);  // 借助C，从A移到B
    move(n, A, C);          // 将最大的盘子移到C
    hanoi(n - 1, B, A, C);  // 借助A，从B移到C
}

int main() {
    int n;
    while (cin >> n) {
        hanoi(n, 'A', 'B', 'C');
        printf("\n");
    }
}