#include <stdio.h>
#include <stdlib.h> // 悼利 皋葛府 包府
#define SIZE 100000

int stack[SIZE];
int top = -1;

int empty() { return top < 0; }

void push(int val) { stack[++top] = val; }

int pop() {
    if (empty())
        return 0;
    else
        return stack[top--];
}

int main() {
    int n, i, target, j = 1, res, k = 0;
    char* result;
    scanf("%d", &n);

    result = (char*)malloc(sizeof(char) * ((n * 2) + 1));

    for (i = 0; i < n; i++) {
        scanf("%d", &target);

        while (j <= target) {
            push(j);
            result[k++] = '+';
            j++;
        }

        res = pop();
        if (res == target) {
            result[k++] = '-';
        }
        else {
            printf("NO");
            free(result);
            return 0;
        }
    }

    for (i = 0; i < n * 2; i++) {
        printf("%c\n", result[i]);
    }

    return 0;
}