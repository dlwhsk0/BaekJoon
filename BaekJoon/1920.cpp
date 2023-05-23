#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second)
{
	int* a = (int*)first;
	int* b = (int*)second;

	if (*a < *b)
		return -1;
	else
		return 1;
	return 0;
}

int binary_search(int list[], int n, int key)
{
	int left, mid, right;
	left = 0, right = n - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (list[mid] == key)
			return 0;
		else if (list[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return 1;
}

int main()
{
	int n, m, i, data;
	int* list;

	scanf("%d", &n);

	list = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf(" %d", &list[i]);
	}

	qsort(list, n, sizeof(list[0]), compare);

	scanf(" %d", &m);

	for (i = 0; i < m; i++)
	{
		scanf(" %d", &data);

		if (binary_search(list, n, data) == 0)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}