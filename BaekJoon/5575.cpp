#include <stdio.h>
#include <stdlib.h>


int main() {
    int h1, m1, s1, sum1; // 출근 시간
    int h2, m2, s2, sum2; // 퇴근 시간

    for (int i = 0; i < 3; i++) {
        scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);

        if (s2 < s1) {
            s2 += 60;
            if (m2 <= 0) {
                m2 += 60;
                h2--;
            }
            m2--;
        }
        if (m2 < m1) {
            m2 += 60;
            h2--;
        }

        printf("%d %d %d\n", h2 - h1, m2 - m1, s2 - s1);
    }

    return 0;
}