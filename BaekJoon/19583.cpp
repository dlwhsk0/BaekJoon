#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

// stoi�� ���ڿ� �ð��� int�� ��ȯ
/*
������ȸ ���̸� first�� ����
������ȸ ���� ��Ʈ���� ������(����)���� ä�� ��� Ȯ��
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s, e, q, time, name;
	int st, et, qt, t, cnt = 0;

	cin >> s >> e >> q; // ����, ��, ��Ʈ����
	set<string> first; // �ߺ� �ڵ� ����

	st = 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
	et = 60 * stoi(e.substr(0, 2)) + stoi(e.substr(3, 2));
	qt = 60 * stoi(q.substr(0, 2)) + stoi(q.substr(3, 2));

	while (cin >> time >> name) {
		t = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3, 2));

		if (t <= st) { first.insert(name); } // ������ȸ ��, ����
		if (t >= et && t <= qt) { // ������ȸ ������ ��Ʈ���� ��
			if (first.find(name) != first.end()) { // ����������
				cnt++;
				first.erase(name); // ī��Ʈ �� ����
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}