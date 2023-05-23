#include <stdio.h>
int prime[1000001];

int main() {
    int n, same = 0, count = 0;
    long long mul = 1;
    int arr[10001] = { 0 };
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // 수열 입력 받기
        scanf("%d", &arr[i]);
    }

    for (int i = 2; i <= 1000000; i++) { // 에라토스테네스 체
        if (prime[i] == 0) {
            for (int j = 2; j * i <= 1000000; j++) {
                prime[j * i] = 1; // 합성수 체크  
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (prime[arr[i]] == 0) { // 소수일 때
            count++;

            for (int j = 0; j < i; j++) { // 중복 검사
                if (arr[j] == arr[i]) {
                    same = 1;
                    break;
                }
            }

            if (same == 0) { mul *= arr[i]; }
        }
    }
    if (count != 0) { printf("%lld", mul); }
    else { printf("-1"); }

    return 0;
}