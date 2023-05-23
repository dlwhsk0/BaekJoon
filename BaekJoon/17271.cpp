#include <iostream>
#include <algorithm>
using namespace std;

/*
���� ��ȹ��:
�ϳ��� ������ �� �ѹ��� Ǯ����, ������� �Ź� �����ϴ� �˰���.
�ٽ� ����� �ʿ��� �� ������ �̹� ����� ���� �ҷ���

2624�� ���� �ٲٱ� ����

a��ų�� 1��
*/

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long dp[10005] = { 1, 1 };
	long long n, m, i; // �ο�ð�, b��ų
	cin >> n >> m;

	for (i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + (i - m >= 0 ? dp[i - m] : 0)) % 1000000007;
	}
	cout << dp[n] << endl;

	return 0;
}