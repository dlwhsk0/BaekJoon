#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n, c, csum; // �б� ��, ���� ��, �� ���� �� ����
    float g, sum;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) { // �б�
        sum = 0; csum = 0;
        scanf("%d", &n);

        for (int j = 0; j < n; j++) { // ����
            scanf("%d %f", &c, &g);
            csum += c;
            sum += c * g;
        }

        printf("%d %f\n", csum, sum / csum);
    }

    return 0;
}