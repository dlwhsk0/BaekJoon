#include <stdio.h>
int que[500001];

int main() {
    int n, front = 0, rear;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // 카드 입력
        que[i] = i + 1;
    }
    rear = n - 1;

    while (1) {
        front = (front + 1) % n; // 제일 앞 카드 삭제

        if (rear == front) // 남은 카드 확인
            break;

        rear = (rear + 1) % n; // 끝 번호를 제일 앞으로
        que[rear] = que[front]; // 제일 앞 카드를 제일 끝으로
        front = (front + 1) % n; // 앞 번호 +1

        if (rear == front) // 남은 카드 확인
            break;
    }

    printf("%d", que[rear]);

    return 0;
}