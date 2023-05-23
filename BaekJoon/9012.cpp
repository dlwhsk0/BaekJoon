#include <stdio.h>
#include <string.h>
#define MAX 51

int main() {
    char arr[MAX] = { 0 };
    int test, t, count, len, l;

    scanf("%d", &test);

    for (t = 0; t < test; t++) {
        scanf("%s", arr);
        len = strlen(arr);

        for (l = 0, count = 0; l < len; l++) {
            arr[l] == '(' ? count++ : count--;

            if (count < 0) { break; }
        }

        if (count == 0) { printf("YES\n"); }
        else { printf("NO\n"); }
    }

    return 0;
}