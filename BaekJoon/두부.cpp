#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int player[100001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, ans = 0;
	cin >> n >> m >> k;

	//m번이 3모인데 이걸 기준으로 양쪽이 시계방향
	player[m] = 3;
	player[(m - 1 + n) % n] = 2;
	player[(m - 2 + n) % n] = 1;

	for (int i = 4; i <= n; i++) {
		m = (m + 1) % n;
		player[m] = i;
	}

	for (int i = 1; i <= n; i++) {
		if (player[i] == k) { ans = i; }
	}
	cout << ans;

	return 0;
}