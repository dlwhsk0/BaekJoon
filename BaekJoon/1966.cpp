#include <stdio.h>
int main() {
	int t, n, q;
	int queue[100] = { 0 };

	scanf("%d", &t);

	for (int i = 0; i < t; i++) { // 테스트 케이스 개수
		scanf("%d %d", &n, &q); // 문서의 개수와 궁금한 문서의 처음 인덱스

		int count = 1;
		int front = 0;
		int max = 0; // 초기화

		for (int j = 0; j < n; j++) {
			scanf("%d", &queue[j]); // n개 문서의 중요도 입력
		}

		while (1) {
			for (int k = 0; k < n; k++) { // 최댓값 찾기
				if (queue[k] > max) {
					max = queue[k];
				}
			}

			while (queue[front] != max) { // 최댓값에 도착할 때까지 front 증가
				front = (front + 1) % n;
			}

			if (front == q) { break; }

			queue[front] = 0; // 프린트
			front = (front + 1) % n;
			max = 0; // 최댓값 초기화
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}