#include <stdio.h>
#include <stdlib.h> // malloc(), qsort()

/*
���� �޸� �Ҵ� �غ���
1. ���̿� �̸�, �켱������ �� ����ü ����
2. n���� ����ü ���� �޸� �Ҵ�
3. ȸ�� ���� �Է� �ް�
4. >> qsort() << ���
5. ���ĵ� �迭 ���
*/

/*
void qsort(void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);
base: ������ �迭�� ������
nel: �� ���ҵ��� �� ��
width: ���� �ϳ��� ũ��
compare: �񱳸� ������ �Լ��� ������
*/

typedef struct { // ����ü ����
    int age;
    char name[101];
} member;

int compare(void* first, void* second) { // qsort �� �Լ�
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    member* m = (member*)malloc(n * sizeof(member));

    for (i = 0; i < n; i++) { // ȸ�� ���� �Է�
        scanf("%d %s", &m[i].age, m[i].name);
    }

    qsort(m, n, sizeof(member), compare);

    for (i = 0; i < n; i++) {
        printf("%d %s\n", m[i].age, m[i].name);
    }

    return 0;
}