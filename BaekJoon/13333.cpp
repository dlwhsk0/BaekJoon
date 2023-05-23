#include <stdio.h>

int main() {
    int paper[1001] = { 0 };
    int n, q, k, count;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // 각 논문의 인용 횟수
        scanf("%d", &paper[i]);
    }

    for (int i = 0; i <= 10000; i++) { // q-인덱스 범위: 0~10000
        count = 0;
        for (int j = 0; j < n; j++) { // i번 이상 인용된 논문 세기
            if (i <= paper[j]) {
                count++;
            }
        }
        if (count >= i) { q = i; }

        k = 0;
        for (int j = 0; j < n; j++) { // 인용횟수가 k번 이하인 논문이 n-q개
            if (k >= paper[j]) { k++; }
        }
        if (k == n - q) { break; }
    }
    printf("%d", q);

    return 0;
}