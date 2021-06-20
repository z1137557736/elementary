#include <cstdio>

const int MAX_SIZE = 50;

// 共享栈
struct ShareStack {
    int data[MAX_SIZE]; // 顺序栈
    int top[2]; // top为两个栈顶的指针
};

// 初始化栈
void init(ShareStack *&stack) {
    stack -> top[0] = -1;
    stack -> top[1] = MAX_SIZE;
}

// 共享栈的入栈方法，先变更指针再存值
void push(ShareStack *&stack, int i, int x) {
    if (i < 0 || i > 1) {
        printf("illegalParameterException");
        return;
    }
    if (stack -> top[1] - stack -> top[0] == 1) {
        printf("stackOverflowException");
        return;
    }
    // 入对应栈
    switch (i) {
        case 0: stack -> data[++stack -> top[i]] = x; break;
        case 1: stack -> data[--stack -> top[i]] = x; break;
    }
}

// 共享栈的出栈方法，先取再变更指针
bool pop(ShareStack *&stack, int i, int &x) {
    if (i < 0 || i > 1) {
        printf("illegalParameterException");
        return false;
    }
    switch (i) {
        case 0:
            if (stack -> top[i] == -1) {
                return false;
            } else {
                x = stack -> data[stack -> top[i]--];
                return true;
            }
        case 1:
            if (stack -> top[i] == MAX_SIZE) {
                return false;
            } else {
                x = stack -> data[stack -> top[i]++];
                return true;
            }
    }
}