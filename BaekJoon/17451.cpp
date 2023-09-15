#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 역순으로 탐색하면서 현재의 값의 배수면서 이전값보다 큰 수를 찾는다

int arr[300000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, n;
	long long ans;

	cin >> n;
	for (i = 0; i < n; i++) { cin >> arr[i]; }

	ans = arr[n - 1]; // 가장 마지막 값
	for (i = n - 2; i >= 0; i--) { // 역순으로 탐색
		if (ans % arr[i] == 0) { continue; }
		else { ans = arr[i] * (ans / arr[i] + 1); }
	}
	cout << ans;

	return 0;
}