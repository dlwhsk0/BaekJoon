#include <stdio.h>

int main() {
    int N, L, D;
    scanf("%d %d %d", &N, &L, &D);

    int album = (L + 5) * N - 6;
    int sec = 0, play, bell;

    //printf("album : %ds\n", album);

    while (1) {
        //printf("\n%ds", sec);
        play = sec % (L + 5);
        bell = sec % (D);

        if (play < L) { // 재생 중
          //printf(" ~~play~~");
        }
        else { // 재생 중이지 않을 때
          //printf(" stop");
            if (bell == 0) {
                //printf(" !!!!!!!!!");
                printf("%d", sec);
                break;
            }
        }

        if (bell == 0) {
            //printf(" !!!!!!!!!");
            if (sec > album) {
                printf("%d", sec);
                break;
            }
        }

        sec++;
    }

    return 0;
}