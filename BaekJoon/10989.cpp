#include <stdio.h>

int main() {
    int arr[100001] = { 0 }; // 초기화
    int n, temp;
    scanf("%d", &n);

    // 숫자를 입력 받고 해당 배열을 1 증가 시킨다
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        arr[temp]++;
    }

    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}