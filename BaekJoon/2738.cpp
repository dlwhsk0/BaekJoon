#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, i, j;
	cin >> n >> m;

	int** a = new int* [n + 1];
	int** b = new int* [n + 1];

	for (i = 1; i <= n; i++) {
		a[i] = new int[m + 1];
		b[i] = new int[m + 1];
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> b[i][j];
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}