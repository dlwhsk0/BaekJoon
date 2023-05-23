#include <stdio.h>

int main() {
    int N, max = 0, leader; // 학생 수
    int cls[1001][6] = { 0 }; // 학생 별 반 배열
    int stu[1001] = { 0 }; // 학생 별 같은 반이었던 학생 수

    scanf("%d", &N); // N 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &cls[i][j]); // 반 기록
        }
    }

    for (int i = 0; i < N; i++) { // 검사 대상
        for (int j = 0; j < N; j++) { // 친구들

            for (int k = 0; k < 5; k++) { // 학년
                if (cls[i][k] == cls[j][k]) {
                    stu[i]++;
                    break;
                }
            }

        }
    }

    for (int i = 0; i < N; i++) {
        if (max < stu[i]) {
            max = stu[i];
            leader = i;
        }
    }

    printf("%d", leader + 1);

    return 0;
}
