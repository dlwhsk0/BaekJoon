#include <iostream>
#include <algorithm>
using namespace std;

/*
동적 계획법:
하나의 문제는 단 한번만 풀도록, 결과값을 매번 저장하는 알고리즘.
다시 계산이 필요할 때 기존에 이미 저장된 값을 불러옴

2624번 동전 바꾸기 참고

a스킬은 1초
*/

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long dp[10005] = { 1, 1 };
	long long n, m, i; // 싸움시간, b스킬
	cin >> n >> m;

	for (i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + (i - m >= 0 ? dp[i - m] : 0)) % 1000000007;
	}
	cout << dp[n] << endl;

	return 0;
}