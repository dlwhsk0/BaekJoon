#include <stdio.h>
#include <stdlib.h> // ���� �޸�
#include <string.h> // string ���� �Լ�

typedef struct {
	int len;
	char str[51];
} word;

int compare(const void* first, const void* second)
{
	word* a = (word*)first;
	word* b = (word*)second;

	if (a->len < b->len) { return -1; }
	else if (a->len > b->len) { return 1; }
	else if (a->len == b->len) {
		if (strcmp(a->str, b->str) < 0) { return -1; }
		else { return 1; }
	}
	return 0;
}

int main()
{
	int i, j, n;
	word* text;

	scanf("%d", &n);

	text = (word*)calloc(n + 1, sizeof(word)); // ���� �Ҵ�

	for (i = 0; i < n; i++)
	{
		scanf(" %s", text[i].str);
		text[i].len = strlen(text[i].str);

		for (j = 0; j < i; j++) { // �ߺ�
			if (strcmp(text[i].str, text[j].str) == 0) {
				i -= 1;
				n -= 1;
				break;
			}
		}
	}

	qsort(text, n, sizeof(text[0]), compare); // �� ����

	for (i = 0; i < n; i++) {
		printf("%s\n", text[i].str);
	}

	return 0;
}