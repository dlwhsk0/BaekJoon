#include <stdio.h>
#include <string.h>

int main() {
    int N, len, pw;
    scanf("%d", &N);
    char word[101][16] = { 0 };

    for (int i = 0; i < N; i++) { // 입력 받기
        scanf("%s", word[i]);
    }

    for (int i = 0; i < N; i++) {
        pw = 1;
        len = strlen(word[i]);
        for (int j = 0; j < len / 2; j++) { // 펠린드롬 검사
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

    for (int i = 0; i < N; i++) { // 검색 대상 단어
        len = strlen(word[i]);

        for (int j = 0; j < N; j++) { // 다른 단어
            if (len == strlen(word[j])) { // 길이 검색

                pw = 1;
                for (int k = 0; k < len; k++) { // 단어 검색
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