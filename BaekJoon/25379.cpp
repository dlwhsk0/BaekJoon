#include <iostream>
#include <algorithm>
using namespace std;

/*
홀수와 짝수가 인접한 경우가 최대 1번 등장하도록. 0은 짝수
"짝수는 왼쪽 홀수는 오른쪽" or "홀수는 왼쪽 짝수는 오른쪽"
>> 짝수가 나올때마다 그 전에 나온 홀수의 개수를 답에 더해주기
*/

int arr[1000001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long n, i, c0 = 0, c1 = 0, cnt0 = 0, cnt1 = 0;

	cin >> n;
	for (i = 0; i < n; i++) { cin >> arr[i]; }

	for (i = 0; i < n; i++) {
		if ((arr[i] % 2)) { // 홀수
			c1++;
			cnt0 += c0;
		}
		else { // 짝수
			c0++;
			cnt1 += c1;
		}
	}
	cout << min(cnt0, cnt1);

	return 0;
}