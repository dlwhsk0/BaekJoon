#include <stdio.h>
#include <stdlib.h> // malloc()

int main() {
    int n, hp = 100, joy = 0, i, j;
    scanf("%d", &n);

    int lost[21] = { 0 };
    int get[21] = { 0 };

    for (i = 1; i <= n; i++) { scanf("%d", &lost[i]); }
    for (i = 1; i <= n; i++) { scanf("%d", &get[i]); }

    int max[21][100] = { 0 };

    /*
    1. �λ� ���� ���� �Ǵ�
        1) �λ� ���� - �ִ����� �˻�
            1)) �ִ��̸� max[i-1][99-lost[i]] + get[i] �� ����
            2)) �ƴϸ� �� ĭ�� ���� ������
        2) �λ� �Ұ���
            �� ĭ�� ���� �����´�
    */

    for (i = 1; i <= n; i++) { // ��� ��ȣ
        for (j = 1; j <= 99; j++) { // ü��
            if (lost[i] <= j) { // 1. �λ� ���� ���� �Ǵ�
                // 1) �λ� ����
                if (max[i - 1][j - lost[i]] + get[i] > max[i - 1][j]) {
                    max[i][j] = max[i - 1][j - lost[i]] + get[i];
                }
                else {
                    max[i][j] = max[i - 1][j];
                }
            }
            else { // 2) �λ� �Ұ���
                max[i][j] = max[i - 1][j];
            }
        }
    }

    int max_joy = -1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 99; j++) {
            if (max_joy < max[i][j]) { max_joy = max[i][j]; }
        }
    }

    printf("%d", max_joy);

    return 0;
}
