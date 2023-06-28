#include <iostream>
using namespace std;

double arr[10001];

int main() {
	int n, i, j;
	double ans = 0;

	cin >> n; // 양의 실수들의 개수

	for (i = 0; i < n; i++) { cin >> arr[i]; }

	for (i = 0; i < n; i++) {
		if (i == 0) { ans = arr[i]; }
		else {
			if (arr[i] * arr[i - 1] >= arr[i]) { // 최댓값
				arr[i] = arr[i - 1] * arr[i]; // 업데이트
			}
			ans = max(ans, arr[i]);
		}
	}

	printf("%.3lf", ans);
	return 0;
}