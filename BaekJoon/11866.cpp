#include<stdio.h>

typedef struct {
    int data[1000];
    int front, rear;
} Queue;

void push(Queue* queue, int data) {
    queue->data[queue->rear++ % 1000] = data;
}

int pop(Queue* queue) {
    int data = queue->data[queue->front++ % 1000];
    return data;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Queue queue;
    queue.front = queue.rear = 0;

    for (int i = 0; i < N; i++) {
        push(&queue, i + 1);
    }

    printf("<");

    while (queue.rear - queue.front != 0) {
        for (int i = 0; i < K - 1; i++) {
            push(&queue, pop(&queue));
        }
        if (queue.rear - queue.front != 1) {
            printf("%d, ", pop(&queue));
        }
        else {
            printf("%d>", pop(&queue));
        }
    }

    return 0;
}