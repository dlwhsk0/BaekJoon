#include <stdio.h>

int l;
unsigned long long num;
long long r = 1, MOD = 1234567891;
char str[51];

int main() {

    scanf("%d %s", &l, str);

    for (int i = 0; i < l; i++) {
        num += (str[i] - 'a' + 1) * r;
        num %= MOD;

        r *= 31;
        r %= MOD;
    }

    printf("%llu", num);
}