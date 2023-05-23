#include <stdio.h>

int main() {
    int n, m, temp, black = 0;
    int card[101] = { 0 };

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) { // N���� ī�� �Է�
        scanf("%d", &card[i]);
    }

    // ���� for�� ���
    for (int i = 1; i <= n - 2; i++) { // ù ��° ī��
        for (int j = i + 1; j <= n - 1; j++) { // �� ��° ī��
            for (int k = j + 1; k <= n; k++) { // �� ��° ī��
                temp = card[i] + card[j] + card[k];
                if (temp <= m) { // M�� ���� �����鼭
                    if (temp > black) { black = temp; } // �ִ�
                }
            }
        }
    }
    printf("%d", black);

    return 0;
}