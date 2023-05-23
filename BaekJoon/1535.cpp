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
    1. 인사 가능 여부 판단
        1) 인사 가능 - 최대인지 검사
            1)) 최대이면 max[i-1][99-lost[i]] + get[i] 값 저장
            2)) 아니면 윗 칸의 값을 가져옴
        2) 인사 불가능
            윗 칸의 값을 가져온다
    */

    for (i = 1; i <= n; i++) { // 사람 번호
        for (j = 1; j <= 99; j++) { // 체력
            if (lost[i] <= j) { // 1. 인사 가능 여부 판단
                // 1) 인사 가능
                if (max[i - 1][j - lost[i]] + get[i] > max[i - 1][j]) {
                    max[i][j] = max[i - 1][j - lost[i]] + get[i];
                }
                else {
                    max[i][j] = max[i - 1][j];
                }
            }
            else { // 2) 인사 불가능
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
