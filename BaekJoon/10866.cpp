#include <stdio.h>
#include <string.h>
#define MAX 10001 // ���� �ִ� ��� ����

int deque[MAX] = { 0 }; // ���� ��
int front, rear;

void init() { // ���� �ʱ�ȭ ��Ű�� �Լ�
    front = 0;
    rear = 0;
}
int empty() { // ���� ������� �˻��ϴ� �Լ� : front�� rear�� ��ġ�� ���� ���
    return front == rear;
}
int full() { // ���� ���� á���� �˻��ϴ� �Լ�: front�� rear���� �� ĭ �տ� �ִ� ���
    return ((rear + 1) % MAX == front);
}
int size() { // ���� ���� ������ ��ȯ�ϴ� �Լ�
    return ((rear - front + MAX) % MAX);
}

void push_front(int data) { // ���� �� �տ� ������ �����ϴ� �Լ�
    if (full()) { printf("-1\n"); }
    else {
        deque[front] = data;
        front = (front - 1 + MAX) % MAX;
    }
}
void push_back(int data) { // ���� �� �ڿ� ��Ҹ� �����ϴ� �Լ� == ť�� enqueue()
    if (full()) { printf("-1\n"); }
    else {
        rear = (rear + 1) % MAX;
        deque[rear] = data;
    }
}

void pop_front() { // ���� �� ���� ������ ���� ����ϴ� �Լ� == ť�� dequeue()
    if (empty()) { printf("-1\n"); }
    else {
        front = (front + 1) % MAX;
        printf("%d\n", deque[front]);
    }
}
void pop_back() { // ���� �� ���� ������ ���� ����ϴ� �Լ�
    if (empty()) { printf("-1\n"); }
    else {
        printf("%d\n", deque[rear]);
        rear = (rear - 1 + MAX) % MAX;
    }
}

void dfront() { // ���� ���� �տ� �ִ� ������ ����ϴ� �Լ�
    int temp;

    if (empty()) { printf("-1\n"); }
    else {
        temp = (front + 1) % MAX;
        printf("%d\n", deque[temp]);
    }
}
void dback() { // ���� ���� �ڿ� �ִ� ������ ����ϴ� �Լ�
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