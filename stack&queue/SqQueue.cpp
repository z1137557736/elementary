#include <cstdio>
#define MAX_SIZE 50

// 顺序(循环)队列
// 循环队列的核心思路是将数组看成一个环，而实现它的核心思路为对MAX_SIZE取余
struct Queue {
    int data[MAX_SIZE];
    int front, rear;    // 对头指针与队尾指针
};

// 初始化顺序队列
Queue* init() {
    Queue *queue = new Queue;
    queue -> front = queue -> rear = 0;
    return queue;
}

// 判断顺序队列是否为空队列
bool empty(Queue *queue) {
    return queue -> front == queue -> rear;
}

// 若队列未满，入队
bool push(Queue *&queue, int x) {
    // 队满（若队尾指针的下个位置为队头指针时，则为队满）
    if ((queue -> rear + 1) % MAX_SIZE == queue -> front) return false;
    //三部曲 存值 加1 取余
    queue -> data[queue -> rear] = x;
    queue -> rear = (queue -> rear + 1) % MAX_SIZE;
    return true;
}

// 若不为空队列，出队，x为引用传递
bool pop(Queue *&queue, int &x) {
    if (empty(queue)) {
        return false;
    }
    //三部曲 取值 加1 取余
    x = queue -> data[queue -> front];
    queue -> front = (queue -> front + 1) % MAX_SIZE;
    return true;
}