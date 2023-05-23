#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

int compare(const void* a, const void* b) {
    point A = *(point*)a;
    point B = *(point*)b;
    if (A.y > B.y)
    {
        return 1;
    }
    else if (A.y == B.y)
    {
        if (A.x > B.x)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    int test;
    scanf("%d", &test);
    point* arr;
    arr = (point*)malloc(sizeof(point) * test);
    for (int i = 0; i < test; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, test, sizeof(point), compare);
    for (int i = 0; i < test; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    free(arr);
    return 0;
}