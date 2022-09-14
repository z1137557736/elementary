#include <cstdio>

const int MAX_SIZE = 10;

int father[MAX_SIZE] = {};

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        father[i] = i;
    }
}

int findFather(int x) {
    if (father[x] == x) {
        return x;
    }
    // 路径压缩
    return father[x] = findFather(x);
}

void merge(int a, int b) {
    // 寻找a与b的根结点
    int fa = findFather(a);
    int fb = findFather(b);
    // 若根结点不同，则合并两个集合
    if (fa != fb) {
        father[fa] = fb;
    }
}

int main() {
    return 0;
}