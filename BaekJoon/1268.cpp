#include <stdio.h>

int main() {
    int N, max = 0, leader; // �л� ��
    int cls[1001][6] = { 0 }; // �л� �� �� �迭
    int stu[1001] = { 0 }; // �л� �� ���� ���̾��� �л� ��

    scanf("%d", &N); // N �Է�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &cls[i][j]); // �� ���
        }
    }

    for (int i = 0; i < N; i++) { // �˻� ���
        for (int j = 0; j < N; j++) { // ģ����

            for (int k = 0; k < 5; k++) { // �г�
                if (cls[i][k] == cls[j][k]) {
                    stu[i]++;
                    break;
                }
            }

        }
    }

    for (int i = 0; i < N; i++) {
        if (max < stu[i]) {
            max = stu[i];
            leader = i;
        }
    }

    printf("%d", leader + 1);

    return 0;
}
