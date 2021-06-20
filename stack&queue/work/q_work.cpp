#include <cstdio>
#define MAX_SIZE 50

// 循环队列
struct Queue {
    int data[MAX_SIZE]; // 存放数据
    int front, rear;    // 头指针 尾指针
    int tag;    // 区别空队列和满队列 0 空队列 1 满队列
};

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

// 入栈需判断栈是否已满
bool stackPush(Stack* stack, int x) {
    // 栈已满
    if (stack -> top == MAX_SIZE - 1) {
        return false;
    }
    // 先自增 再存值
    stack -> data[++stack -> top] = x;
    return true;
}

// 出栈前需判断栈是否为空栈
bool stackPop(Stack* stack, int &x) {
    // 空栈
    if (stack -> top == -1) {
        return false;
    }
    // 先取值 再自减
    x = stack -> data[stack -> top--];
}

// 初始化循环队列
Queue* initQueue() {
    Queue *q = new Queue;
    q -> front = q -> rear = 0;
    // 则无需空出一个结点元素用于区分空队列与满队列的区别
    q -> tag = 0;
    return  q;
}

//  入队前需判断是否满队列
bool push(Queue *&q, int x) {
    // 队列已满
    if (q -> front == q -> rear && q -> tag == 1) {
        return false;
    }
    q -> data[q -> rear] = x;
    q -> rear = (q -> rear + 1) % MAX_SIZE;
    // 元素入队后，队列必不为空队列
    q -> tag = 1;
    return true;
}

// 出队前需判断是否为空队列
bool pop(Queue *&q, int &x) {
    // 空队列
    if (q -> rear == q -> front && q -> tag == 0) {
        return false;
    }
    x = q -> data[q -> front];
    q -> front = (q -> front + 1) % MAX_SIZE;
    // 元素出队之后，队列必不为满队列
    q -> tag = 0;
}

// 利用栈将队列的元素逆置
void work2() {
    Queue *q = initQueue();
    // 空栈
    Stack *s = initStack();
    for (int i = 1; i <= 5; i++) {
        // 元素入队
        push(q, i);
    }
    for (int i = 1; i <= 5; i++) {
        int x;
        // 元素出队并压入栈中
        pop(q, x);
        stackPush(s, x);
    }
    for (int i = 1; i <= 5; i++) {
        int x;
        // 出栈再入队，实现队列逆置
        stackPop(s, x);
        push(q, x);
    }
    return;
}

int main() {
    work2();
}