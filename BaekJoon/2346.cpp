#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[1000];
    int n, i, j, k; // ǳ�� ����
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // ǳ�� �� ���� �Է�
        scanf("%d", &arr[i]);
    }

    // ù��° ǳ������ ��Ʈ����.
    int now = 0, go = arr[0];
    arr[0] = n + 1; // ���� ǳ��
    printf("1 ");

    // ���� ǳ��
    for (i = 0; i < n - 1; i++) {

        if (go > 0) { // ������ �̵� : ���

            // ���� ǳ�� ���
            for (j = go; j > 0; j--) {
                now = (now + 1) % n;
                if (arr[now] == n + 1) { j++; }
            }
        }
        else { // ���� �̵� : ����

            // ���� ǳ�� ���
            for (j = go; j < 0; j++) {
                now = ((now - 1) + n) % n;
                if (arr[now] == n + 1) { j--; }
            }
        }
        go = arr[now];
        arr[now] = n + 1;
        printf("%d ", now + 1);
    }

    return 0;
}