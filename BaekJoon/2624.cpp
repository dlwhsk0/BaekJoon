#include <iostream>
#include <algorithm>
using namespace std;

/*
지폐의 금액 T (0＜T ≤ 10,000)
동전의 가지 수 k (0＜k ≤ 100)
{ 동전의 금액 pi (0＜pi ≤ T), 개수 ni (0＜ni ≤ 1,000) }
*/

pair<int, int> a[101];
int coin[10001] = { 0 }; // 1~10000원을 동전으로 교환 가능한 각 경우의 수 

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, k, n, m, i, j, y; // 금액, 가짓수, { 종류, 개수 }
	cin >> t >> k;

	for (i = 0; i < k; i++) {
		cin >> n >> m;
		a[i] = make_pair(n, m); // 동전 금액, 개수 페어 생성
	}

	coin[0] = 1;
	for (i = 0; i < k; i++) { // 모든 동전 종류 검사
		for (j = t; j > 0; j--) { // t원 ~ 1원
			for (y = 1; y <= a[i].second; y++) { // 동전 개수 끝까지
				if (j - (a[i].first * y) >= 0) {
					coin[j] += coin[j - (a[i].first * y)];
					// cout << "coin[" << j << "] += coin[" << j - (a[i].first*y) << "]" << endl;
				}
			}
		}
	}
	cout << coin[t] << endl;

	return 0;
}