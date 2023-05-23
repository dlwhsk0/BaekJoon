#include <stdio.h>
#include <stdlib.h>

typedef struct { // ����ü
    int x;
    int y;
} coord;

int compare(const void* a, const void* b) { // �������� ���� ���� ��
    coord A = *(coord*)a;
    coord B = *(coord*)b;

    if (A.x > B.x)
        return 1;
    else if (A.x == B.x) { // x��ǥ ��
        if (A.y > B.y) // y��ǥ ��
            return 1;
        else
            return -1;
    }
    return -1; // A.x < B.x�� -1
}

int main() {
    int n, i = 0;
    scanf("%d", &n);
    coord arr[n]; // ����ü�� �迭

    while (i < n) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        i++;
    }

    qsort(arr, n, sizeof(coord), compare);

    i = 0; // �ʱ�ȭ
    while (i < n) {
        printf("%d %d\n", arr[i].x, arr[i].y); // ���ĵ� �迭 ���
        i++;
    }

    return 0;
}