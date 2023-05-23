#include <stdio.h>
#include <string.h>

int main() {
    int N, len, pw;
    scanf("%d", &N);
    char word[101][16] = { 0 };

    for (int i = 0; i < N; i++) { // �Է� �ޱ�
        scanf("%s", word[i]);
    }

    for (int i = 0; i < N; i++) {
        pw = 1;
        len = strlen(word[i]);
        for (int j = 0; j < len / 2; j++) { // �縰��� �˻�
            if (word[i][j] != word[i][len - 1 - j]) {
                pw = 0;
                break;
            }
        }
        if (pw) {
            printf("%d %c", len, word[i][len / 2]);
            return 0;
        }
    }

    for (int i = 0; i < N; i++) { // �˻� ��� �ܾ�
        len = strlen(word[i]);

        for (int j = 0; j < N; j++) { // �ٸ� �ܾ�
            if (len == strlen(word[j])) { // ���� �˻�

                pw = 1;
                for (int k = 0; k < len; k++) { // �ܾ� �˻�
                    if (word[i][k] != word[j][len - 1 - k]) {
                        pw = 0;
                        break;
                    }
                }
                if (pw) {
                    printf("%d %c", len, word[i][len / 2]);
                    return 0;
                }
            }
        }
    }

    return 0;
}