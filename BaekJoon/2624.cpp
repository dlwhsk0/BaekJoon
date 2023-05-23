#include <iostream>
#include <algorithm>
using namespace std;

/*
������ �ݾ� T (0��T �� 10,000)
������ ���� �� k (0��k �� 100)
{ ������ �ݾ� pi (0��pi �� T), ���� ni (0��ni �� 1,000) }
*/

pair<int, int> a[101];
int coin[10001] = { 0 }; // 1~10000���� �������� ��ȯ ������ �� ����� �� 

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, k, n, m, i, j, y; // �ݾ�, ������, { ����, ���� }
	cin >> t >> k;

	for (i = 0; i < k; i++) {
		cin >> n >> m;
		a[i] = make_pair(n, m); // ���� �ݾ�, ���� ��� ����
	}

	coin[0] = 1;
	for (i = 0; i < k; i++) { // ��� ���� ���� �˻�
		for (j = t; j > 0; j--) { // t�� ~ 1��
			for (y = 1; y <= a[i].second; y++) { // ���� ���� ������
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