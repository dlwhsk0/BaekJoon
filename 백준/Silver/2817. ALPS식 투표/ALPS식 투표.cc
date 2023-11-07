#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

// 1로 나눈 값, 2, 3, ..., 14로 나눈 14개의 실수가 점수
map<char, int> result;
map<int, char, greater<int>> m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, n, score, out = 0, i, k, temp; // 참가자, 스태프 수
	char staff;

	cin >> x;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> staff >> score;
		if (score < (x * 0.05)) { out++; } // 전체 5% 미만은 제외
		else {
			result[staff] = 0; // 칩 0개부터 시작
			for (k = 1; k <= 14; k++) { // 점수 집합 만들기
				m[(score / k)] = staff;
			}
		}
	}

	temp = 14;
	for (auto it : m) {
		if (temp == 0) { break; }
		result[it.second]++;
		temp--;
	}

	for (auto it : result) {
		cout << it.first << " " << it.second << '\n';
	}

	return 0;
}