#include <iostream>
#include <unordered_map> // 정렬 없는 map (해시 맵)
#include <vector>
#include <algorithm>
using namespace std;

/*
존재하면 갱신, 없으면 삽입
*/

unordered_map<string, int> um; // key: 학번 value: 번호
vector<pair<string, int>> v; // value 정렬 위한 벡터

bool compare(const pair<string, int>& a, const pair<string, int>& b) { // value로 정렬
	return a.second < b.second;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k, l, i;
	string str;
	cin >> k >> l; // 수강가능인원, 대기목록길이

	for (i = 0; i < l; i++) { // 입력
		cin >> str;
		um[str] = i;
	}

	for (auto& i : um) { v.push_back(i); } // 벡터 삽입

	sort(v.begin(), v.end(), compare);
	for (i = 0; i < min(k, (int)v.size()); i++) { cout << v[i].first << '\n'; }

	return 0;
}