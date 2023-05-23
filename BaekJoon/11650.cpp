#include <stdio.h>
#include <stdlib.h>

typedef struct { // 구조체
    int x;
    int y;
} coord;

int compare(const void* a, const void* b) { // 오름차순 정렬 위한 비교
    coord A = *(coord*)a;
    coord B = *(coord*)b;

    if (A.x > B.x)
        return 1;
    else if (A.x == B.x) { // x좌표 비교
        if (A.y > B.y) // y좌표 비교
            return 1;
        else
            return -1;
    }
    return -1; // A.x < B.x면 -1
}

int main() {
    int n, i = 0;
    scanf("%d", &n);
    coord arr[n]; // 구조체형 배열

    while (i < n) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        i++;
    }

    qsort(arr, n, sizeof(coord), compare);

    i = 0; // 초기화
    while (i < n) {
        printf("%d %d\n", arr[i].x, arr[i].y); // 정렬된 배열 출력
        i++;
    }

    return 0;
}