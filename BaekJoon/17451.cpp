#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// �������� Ž���ϸ鼭 ������ ���� ����鼭 ���������� ū ���� ã�´�

int arr[300000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, n;
	long long ans;

	cin >> n;
	for (i = 0; i < n; i++) { cin >> arr[i]; }

	ans = arr[n - 1]; // ���� ������ ��
	for (i = n - 2; i >= 0; i--) { // �������� Ž��
		if (ans % arr[i] == 0) { continue; }
		else { ans = arr[i] * (ans / arr[i] + 1); }
	}
	cout << ans;

	return 0;
}