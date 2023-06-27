#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string nlcs = "northlondo";
	string bha = "branksomeh";
	string kis = "koreainter";
	string sja = "johnsburya";

	string str;
	int tmp = 0, top=0;
	bool flag = 1;

	cin >> str;
	//len = str.length(); // 10

	for (int n = 0; n <= 25; n++) {
		// top-n;
		tmp = (top - n + 10) % 10;
		top = tmp;

		//nlcs
		top = tmp;
		for (int i = 0; i < 10; i++) {
			if (str[(top + i) % 10] != nlcs[i]) { flag = 0; break; }
		}
		if (flag) { cout << "NLCS"; return 0; }

		//bha
		top = tmp;
		for (int i = 0; i < 10; i++) {
			if (str[(top + i) % 10] != bha[i]) { flag = 0; break; }
		}
		if (flag) { cout << "BHA"; return 0; }

		//kis
		top = tmp;
		for (int i = 0; i < 10; i++) {
			if (str[(top + i) % 10] != kis[i]) { flag = 0; break; }
		}
		if (flag) { cout << "KIS"; return 0; }

		//sja
		top = tmp;
		for (int i = 0; i < 10; i++) {
			if (str[(top + i) % 10] != sja[i]) { flag = 0; break; }
		}
		if (flag) { cout << "SJA"; return 0; }
	}

	return 0;
}