#include <stdio.h>

int main() {
    int n, m, temp, res = 1;
    scanf("%d %d", &n, &m); // 10,000 ���� �ڿ���

    // �ִ����� ���ϱ� - ���μ� ���� �� �ʿ�?
    if (n > m) { temp = m; }
    else { temp = n; }
    for (int i = temp; i >= 2; i--) { //
        if (n % i == 0 && m % i == 0) {
            res = i; // �ִ����� ����
            break;
        }
    }
    printf("%d\n", res);

    // �ּҰ���� ���ϱ�: N * M / �ִ�����
    res = n * m / res;
    printf("%d", res);

    return 0;
}