#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i;
	cin >> n;

	int* arr = new int[n];
	for (i = 0; i < n; i++) { cin >> arr[i]; }

	sort(arr, arr + n);

	for (i = 0; i < n; i++) { cout << arr[i] << '\n'; }

	return 0;
}