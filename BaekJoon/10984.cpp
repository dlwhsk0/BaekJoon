#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n, c, csum; // 학기 수, 과목 수, 각 학점 과 성적
    float g, sum;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) { // 학기
        sum = 0; csum = 0;
        scanf("%d", &n);

        for (int j = 0; j < n; j++) { // 과목
            scanf("%d %f", &c, &g);
            csum += c;
            sum += c * g;
        }

        printf("%d %f\n", csum, sum / csum);
    }

    return 0;
}