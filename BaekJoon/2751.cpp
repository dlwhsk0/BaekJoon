#include <stdio.h>
#include <stdlib.h> // qsort 함수

int num[1000000];
int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int a = 0; a < n; a++) { // 수 입력 받기
        scanf("%d", &num[a]);
    }

    qsort(num, n, sizeof(int), compare); // 퀵 정렬

    for (int i = 0; i < n; i++) { // 정렬한 수 출력
        printf("%d\n", num[i]);
    }

    return 0;
}