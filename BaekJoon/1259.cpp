#include <stdio.h>
#include <string.h>

int main() {
    char palin[100000] = { 0 };
    int len, check;

    while (1) {
        scanf("%s", palin);
        if (palin[0] == '0') { return 0; }

        len = strlen(palin);
        check = 1;

        for (int i = 0; i < len / 2; i++) {
            if (palin[i] != palin[len - 1 - i]) {
                check = 0;
                break;
            }
        }
        if (check) { printf("yes\n"); }
        else { printf("no\n"); }
    }

    return 0;
}