#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int weight;
	int height;
} sample;

int main() {
	int n;
	scanf("%d", &n);

	int count = 0;
	sample* arr = (sample*)malloc(sizeof(sample) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(arr[i].height), &(arr[i].weight));
	}

	for (int i = 0; i < n; i++) {
		count = 0;

		for (int j = 0; j < n; j++) {
			if ((arr[i].height) < (arr[j].height)) {
				if ((arr[i].weight) < (arr[j].weight)) {
					count = count + 1;
				}
			}
		}

		printf("%d ", count + 1);
	}
}