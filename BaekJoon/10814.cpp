#include <stdio.h>
#include <stdlib.h> // malloc(), qsort()

/*
동적 메모리 할당 해보기
1. 나이와 이름, 우선순위가 들어간 구조체 생성
2. n개의 구조체 동적 메모리 할당
3. 회원 정보 입력 받고
4. >> qsort() << 사용
5. 정렬된 배열 출력
*/

/*
void qsort(void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);
base: 정렬할 배열의 포인터
nel: 각 원소들의 총 수
width: 원소 하나의 크기
compare: 비교를 수행할 함수의 포인터
*/

typedef struct { // 구조체 선언
    int age;
    char name[101];
} member;

int compare(void* first, void* second) { // qsort 비교 함수
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

    for (i = 0; i < n; i++) { // 회원 정보 입력
        scanf("%d %s", &m[i].age, m[i].name);
    }

    qsort(m, n, sizeof(member), compare);

    for (i = 0; i < n; i++) {
        printf("%d %s\n", m[i].age, m[i].name);
    }

    return 0;
}