#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* n장의 공유 숫자카드 / 팀 숫자카드
* 팀 숫자카드 중 k장의 견제받은 숫자카드 (낼 수 없음)
* 공유에서 한 장 팀에서 한 장
* 두 숫자의 곱이 점수, 상대 팀보다 높으면 우승
* 
* >>최선의 방법으로 견제<<
* 벡터로 값을 넣고 최대값 찾기
* 최대값을 만드는 팀 숫자카드 삭제하기
*/

int share[101];
int team[101];
int temp, maxnum;
int n, k, tidx;

void card() {
	maxnum = -100000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (team[j] == 10000) {	continue; }

			temp = share[i] * team[j];

			if (maxnum < temp) {
				maxnum = temp;
				tidx = j; // 최대로 만드는 팀 숫자카드 인덱스
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) { cin >> share[i]; }
	for (int i = 0; i < n; i++) { cin >> team[i]; }

	for(int i = 0; i <= k; i++) { // 견제
		card();
		team[tidx] = 10000; // 견제된 카드 값 변경
	}
	cout << maxnum;

	return 0;
}