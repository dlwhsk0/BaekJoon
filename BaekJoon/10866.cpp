#include <stdio.h>
#include <string.h>
#define MAX 10001 // 덱의 최대 요소 개수

int deque[MAX] = { 0 }; // 원형 덱
int front, rear;

void init() { // 덱을 초기화 시키는 함수
    front = 0;
    rear = 0;
}
int empty() { // 덱이 비었는지 검사하는 함수 : front와 rear의 위치가 같은 경우
    return front == rear;
}
int full() { // 덱이 가득 찼는지 검사하는 함수: front가 rear보다 한 칸 앞에 있는 경우
    return ((rear + 1) % MAX == front);
}
int size() { // 덱의 정수 개수를 반환하는 함수
    return ((rear - front + MAX) % MAX);
}

void push_front(int data) { // 덱의 맨 앞에 정수를 저장하는 함수
    if (full()) { printf("-1\n"); }
    else {
        deque[front] = data;
        front = (front - 1 + MAX) % MAX;
    }
}
void push_back(int data) { // 덱의 맨 뒤에 요소를 저장하는 함수 == 큐의 enqueue()
    if (full()) { printf("-1\n"); }
    else {
        rear = (rear + 1) % MAX;
        deque[rear] = data;
    }
}

void pop_front() { // 덱의 맨 앞의 정수를 빼고 출력하는 함수 == 큐의 dequeue()
    if (empty()) { printf("-1\n"); }
    else {
        front = (front + 1) % MAX;
        printf("%d\n", deque[front]);
    }
}
void pop_back() { // 덱의 맨 뒤의 정수를 빼고 출력하는 함수
    if (empty()) { printf("-1\n"); }
    else {
        printf("%d\n", deque[rear]);
        rear = (rear - 1 + MAX) % MAX;
    }
}

void dfront() { // 덱의 가장 앞에 있는 정수를 출력하는 함수
    int temp;

    if (empty()) { printf("-1\n"); }
    else {
        temp = (front + 1) % MAX;
        printf("%d\n", deque[temp]);
    }
}
void dback() { // 덱의 가장 뒤에 있는 정수를 출력하는 함수
    if (empty()) { printf("-1\n"); }
    else {
        printf("%d\n", deque[rear]);
    }
}

int main() {
    int n, x;
    char cmd[11] = { 0 };
    scanf("%d", &n);

    init();
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(cmd, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(cmd, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(cmd, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(cmd, "front") == 0) {
            dfront();
        }
        else if (strcmp(cmd, "back") == 0) {
            dback();
        }
    }

    return 0;
}