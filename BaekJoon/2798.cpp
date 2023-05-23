#include <stdio.h>

int main() {
    int n, m, temp, black = 0;
    int card[101] = { 0 };

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) { // N장의 카드 입력
        scanf("%d", &card[i]);
    }

    // 삼중 for문 사용
    for (int i = 1; i <= n - 2; i++) { // 첫 번째 카드
        for (int j = i + 1; j <= n - 1; j++) { // 두 번째 카드
            for (int k = j + 1; k <= n; k++) { // 세 번째 카드
                temp = card[i] + card[j] + card[k];
                if (temp <= m) { // M을 넘지 않으면서
                    if (temp > black) { black = temp; } // 최댓값
                }
            }
        }
    }
    printf("%d", black);

    return 0;
}