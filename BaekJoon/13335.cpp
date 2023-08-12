#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[1001];
queue<int> q;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, w, l, time = 0, cnt = 0, i;
	cin >> n >> w >> l;

	for (i = 0; i < n; i++) { cin >> arr[i]; }

	for (i = 0; i < n; i++) {
		while (true) {
			if (q.size() == w) { // 다리 위가 다 차면 최상단 트럭 빼기
				cnt -= q.front();
				q.pop();
			}
			if (cnt + arr[i] <= l) { break; }
			q.push(0);
			time++;
		}
		q.push(arr[i]);
		cnt += arr[i];
		time++;
	}

	cout << time + w << '\n'; // 마지막 트럭 추가

	return 0;
}