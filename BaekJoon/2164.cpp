#include <stdio.h>
int que[500001];

int main() {
    int n, front = 0, rear;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // ī�� �Է�
        que[i] = i + 1;
    }
    rear = n - 1;

    while (1) {
        front = (front + 1) % n; // ���� �� ī�� ����

        if (rear == front) // ���� ī�� Ȯ��
            break;

        rear = (rear + 1) % n; // �� ��ȣ�� ���� ������
        que[rear] = que[front]; // ���� �� ī�带 ���� ������
        front = (front + 1) % n; // �� ��ȣ +1

        if (rear == front) // ���� ī�� Ȯ��
            break;
    }

    printf("%d", que[rear]);

    return 0;
}