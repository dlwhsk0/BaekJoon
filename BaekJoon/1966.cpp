#include <stdio.h>
int main() {
	int t, n, q;
	int queue[100] = { 0 };

	scanf("%d", &t);

	for (int i = 0; i < t; i++) { // �׽�Ʈ ���̽� ����
		scanf("%d %d", &n, &q); // ������ ������ �ñ��� ������ ó�� �ε���

		int count = 1;
		int front = 0;
		int max = 0; // �ʱ�ȭ

		for (int j = 0; j < n; j++) {
			scanf("%d", &queue[j]); // n�� ������ �߿䵵 �Է�
		}

		while (1) {
			for (int k = 0; k < n; k++) { // �ִ� ã��
				if (queue[k] > max) {
					max = queue[k];
				}
			}

			while (queue[front] != max) { // �ִ񰪿� ������ ������ front ����
				front = (front + 1) % n;
			}

			if (front == q) { break; }

			queue[front] = 0; // ����Ʈ
			front = (front + 1) % n;
			max = 0; // �ִ� �ʱ�ȭ
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}