#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[1000];
    int n, i, j, k; // 풍선 개수
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // 풍선 안 종이 입력
        scanf("%d", &arr[i]);
    }

    // 첫번째 풍선부터 터트린다.
    int now = 0, go = arr[0];
    arr[0] = n + 1; // 터진 풍선
    printf("1 ");

    // 다음 풍선
    for (i = 0; i < n - 1; i++) {

        if (go > 0) { // 오른쪽 이동 : 양수

            // 터진 풍선 고려
            for (j = go; j > 0; j--) {
                now = (now + 1) % n;
                if (arr[now] == n + 1) { j++; }
            }
        }
        else { // 왼쪽 이동 : 음수

            // 터진 풍선 고려
            for (j = go; j < 0; j++) {
                now = ((now - 1) + n) % n;
                if (arr[now] == n + 1) { j--; }
            }
        }
        go = arr[now];
        arr[now] = n + 1;
        printf("%d ", now + 1);
    }

    return 0;
}