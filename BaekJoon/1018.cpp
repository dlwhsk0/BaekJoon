#include <stdio.h>

int main() {
    char board[51][51] = { 0 };
    int n, m, min = 100;
    int countw = 0, countb = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { // ü���� �Է� �ޱ�
        scanf("%s", &board[i]);
    }

    char wb[9][9] = {
      "WBWBWBWB",
      "BWBWBWBW",
      "WBWBWBWB",
      "BWBWBWBW",
      "WBWBWBWB",
      "BWBWBWBW",
      "WBWBWBWB",
      "BWBWBWBW"
    };
    char bw[9][9] = { // �� ���� ����� ü���� ����
      "BWBWBWBW",
      "WBWBWBWB",
      "BWBWBWBW",
      "WBWBWBWB",
      "BWBWBWBW",
      "WBWBWBWB",
      "BWBWBWBW",
      "WBWBWBWB"
    };

    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) { // �� ĭ �� �̵�
            countw = 0;
            countb = 0; // �ʱ�ȭ

            for (int x = i, a = 0; x < i + 8; a++, x++) {
                for (int y = j, b = 0; y < j + 8; b++, y++) { // 8*8 �� Ž��
                    if (board[x][y] == wb[a][b]) { countb++; }
                    else { countw++; }
                }
            }

            if (countb < countw) {
                if (countb < min) { min = countb; }
            }
            else {
                if (countw < min) { min = countw; }
            }
        }
    }

    printf("%d", min);

    return 0;
}