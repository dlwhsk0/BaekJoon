#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 셔플한 걸 원상 복구
// 셔플 규칙에 써있는 숫자로 카드 위치를 옮겨주면 된다!

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second; // second로 오름차순 정렬
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, num;
    cin >> n >> k; //숫자 개수, 셔플 횟수

    vector<pair<int, int>> v(n); // 숫자, 순서
    vector<int> d(n); // 셔플 규칙

    for (int i = 0; i < n; i++) {
        cin >> num;
        v[i] = { num, i + 1 };
    }
    for (int i = 0; i < n; i++) { cin >> d[i]; }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) { v[j].second = d[j]; }
        sort(v.begin(), v.end(), compare);
    }

    for (int i = 0; i < n; i++) { cout << v[i].first << " "; }

    return 0;
}