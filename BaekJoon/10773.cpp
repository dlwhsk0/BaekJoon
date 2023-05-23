#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int stack[MAX];
int top = -1;

void init() { top = -1; }

int empty() { return top == -1; }
int full() { return top == MAX - 1; }

int size() { return top + 1; }

void push(int n) {
    if (full()) { printf("스택이 가득 찼음."); }
    stack[++top] = n;
}

int pop() {
    if (empty()) { printf("스택이 비어있음."); }
    return stack[top--];
}


int main() {
    int k, n, sum = 0;
    scanf("%d", &k);

    init();
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);

        if (n != 0) {
            push(n);
            sum += n;
        }
        else {
            n = pop();
            sum -= n;
        }
    }
    printf("%d", sum);

    return 0;
}
