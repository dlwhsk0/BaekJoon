#include <stdio.h>

int main() {
    int paper[1001] = { 0 };
    int n, q, k, count;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // �� ���� �ο� Ƚ��
        scanf("%d", &paper[i]);
    }

    for (int i = 0; i <= 10000; i++) { // q-�ε��� ����: 0~10000
        count = 0;
        for (int j = 0; j < n; j++) { // i�� �̻� �ο�� �� ����
            if (i <= paper[j]) {
                count++;
            }
        }
        if (count >= i) { q = i; }

        k = 0;
        for (int j = 0; j < n; j++) { // �ο�Ƚ���� k�� ������ ���� n-q��
            if (k >= paper[j]) { k++; }
        }
        if (k == n - q) { break; }
    }
    printf("%d", q);

    return 0;
}