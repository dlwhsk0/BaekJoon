#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

// stoi로 문자열 시간을 int로 변환
/*
개강총회 전이면 first에 저장
개강총회 이후 스트리밍 끝나기(포함)까지 채팅 기록 확인
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s, e, q, time, name;
	int st, et, qt, t, cnt = 0;

	cin >> s >> e >> q; // 시작, 끝, 스트리밍
	set<string> first; // 중복 자동 제외

	st = 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
	et = 60 * stoi(e.substr(0, 2)) + stoi(e.substr(3, 2));
	qt = 60 * stoi(q.substr(0, 2)) + stoi(q.substr(3, 2));

	while (cin >> time >> name) {
		t = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3, 2));

		if (t <= st) { first.insert(name); } // 개강총회 전, 저장
		if (t >= et && t <= qt) { // 개강총회 끝이자 스트리밍 끝
			if (first.find(name) != first.end()) { // 입장했으면
				cnt++;
				first.erase(name); // 카운트 후 삭제
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}