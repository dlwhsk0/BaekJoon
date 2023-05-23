#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int sero, garo, inventory, i, j, k, max, min;
    int** height;
    scanf("%d %d %d", &sero, &garo, &inventory);

    height = (int**)malloc(sizeof(int*) * sero);

    for (i = 0; i < sero; i++) {
        height[i] = (int*)malloc(sizeof(int) * garo);
    }

    max = 0, min = 256;
    for (i = 0; i < sero; i++) {
        for (j = 0; j < garo; j++) {
            scanf(" %d", &height[i][j]);

            if (height[i][j] < min) {
                min = height[i][j];
            }
            else if (height[i][j] > max) {
                max = height[i][j];
            }
        }
    }

    int time = 0, min_time = INT_MAX, block_height = 256;

    for (i = max; i >= min; i--) {
        int b = inventory;
        time = 0;

        for (j = 0; j < sero; j++) {
            for (k = 0; k < garo; k++) {
                int diff = height[j][k] - i;

                if (diff < 0) {
                    time -= diff;
                    b += diff;
                }
                else if (diff > 0) {
                    time += diff * 2;
                    b += diff;
                }
            }
        }

        if (b >= 0) {
            if (time < min_time) {
                min_time = time;
                block_height = i;
            }
        }
    }

    printf("%d %d\n", min_time, block_height);

    return 0;
}