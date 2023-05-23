#include <stdio.h>

int main() {
    int n, m, temp, res = 1;
    scanf("%d %d", &n, &m); // 10,000 이하 자연수

    // 최대공약수 구하기 - 소인수 분해 할 필요?
    if (n > m) { temp = m; }
    else { temp = n; }
    for (int i = temp; i >= 2; i--) { //
        if (n % i == 0 && m % i == 0) {
            res = i; // 최대공약수 저장
            break;
        }
    }
    printf("%d\n", res);

    // 최소공배수 구하기: N * M / 최대공약수
    res = n * m / res;
    printf("%d", res);

    return 0;
}