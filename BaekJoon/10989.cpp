#include <stdio.h>

int main() {
    int arr[100001] = { 0 }; // �ʱ�ȭ
    int n, temp;
    scanf("%d", &n);

    // ���ڸ� �Է� �ް� �ش� �迭�� 1 ���� ��Ų��
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        arr[temp]++;
    }

    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}