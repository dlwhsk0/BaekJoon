#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ���ĺ� ���ڸ� �ε����� Ȱ��

int alphabet[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j, t, c;
	bool check = true;
	string str;
	string ans;
	cin >> t;

	for (i = 0; i < t; i++) {
		cin >> str;

		// �ʱ�ȭ
		ans = ""; check = true;
		for (j = 0; j < 26; j++) { alphabet[j] = 0; }

		for (j = 0; j < str.length(); j++) {
			c = (int)(str[j] - 'A');
			alphabet[c]++;
			ans.push_back(str[j]);

			if (alphabet[c] >= 3) { // �� ��° ������ ��
				if (j >= str.length() || str[j + 1] != str[j]) {
					check = false;
					break;
				}

				alphabet[c] = 0; j++;
				ans.push_back(str[j]);
			}
		}

		if (check) { cout << "OK" << '\n'; }
		else { cout << "FAKE" << '\n'; }
	}

	return 0;
}