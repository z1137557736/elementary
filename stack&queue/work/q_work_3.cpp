#include <cstdio>
#define MAX_SIZE 50

// 顺序栈
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// 初始化顺序栈
Stack* initStack() {
    Stack *stack = new Stack;
    stack -> top = -1;
    return stack;
}

// 判断是否栈为空
bool empty(Stack *stack) {
    return stack -> top == -1;
}

// 判断栈是否已满
bool stackOverFlow(Stack *stack) {
    return stack -> top == MAX_SIZE - 1;
}

// 入栈需判断栈是否已满
bool push(Stack* &stack, int x) {
    // 栈已满
    if (stack -> top == MAX_SIZE - 1) {
        return false;
    }
    // 先自增 再存值
    stack -> data[++stack -> top] = x;
    return true;
}

// 出栈前需判断栈是否为空栈
bool pop(Stack* &stack, int &x) {
    // 空栈
    if (stack -> top == -1) {
        return false;
    }
    // 先取值 再自减
    x = stack -> data[stack -> top--];
    return true;
}

// 入队
bool enQueue(Stack *&s1, int x) {
    if (stackOverFlow(s1)) {
        return false;
    }
    push(s1, x);
    return true;
}

// 两个栈模拟出队
bool deQueue(Stack *&s1, Stack *&s2, int &x) {
    if (!empty(s2)) {
        // 出栈
        pop(s2, x);
        return true;
    }
    // 空栈
    if (empty(s1)) {
        return false;
    }
    while (!empty(s1)) {
        int t;
        // 将s1出栈的元素压入s2栈中
        pop(s1, t);
        push(s2, t);
    }
    // 出栈
    pop(s2, x);
    return true;
}

// 判断队列是否为空
bool queueEmpty(Stack *&s1, Stack *&s2) {
    if (empty(s1) && empty(s2)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Stack *s1 = initStack();
    Stack *s2 = initStack();
    enQueue(s1, 1);
    enQueue(s1, 2);
    enQueue(s1, 3);
    int x;
    deQueue(s1, s2, x);
    printf("%d", x);
    deQueue(s1, s2, x);
    printf("%d", x);
    deQueue(s1, s2, x);
    printf("%d", x);
    deQueue(s1, s2, x);
    printf("%d", x);
    return 0;
}