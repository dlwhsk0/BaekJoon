/* ���� ��� �־��� ũ���� ������ ������ : nCk = n! / (k!(n-k)!)
*/

#include <stdio.h>

int fac(int num) {
    int res = 1;
    for (int i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n, k, res;
    scanf("%d %d", &n, &k);

    res = fac(n) / (fac(k) * fac(n - k));
    printf("%d", res);

    return 0;
}