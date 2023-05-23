#include <iostream>
#include <string>

using namespace std;

/*
o일 때 plus에 1씩 더해가며 sum에 추가
x 만날 경우 plus = 1로 초기화
*/

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, i, j, len, sum, plus;
	cin >> t;

	string str;
	for (i = 0; i < t; i++) {
		cin >> str;
		sum = 0;
		plus = 1;

		len = str.length();
		for (j = 0; j < len; j++) {
			if (str[j] == 'X') { plus = 1; }
			else { sum += plus++; }
		}
		cout << sum << endl;
	}


	return 0;
}
