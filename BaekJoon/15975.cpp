#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1. 색상 2. 좌표 순서로 오름차순 정렬
// 전후의 두 거리를 비교해서 최솟값 저장

vector<pair<int, int>> v; // 좌표, 색상

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) { // 색상이 같다면
        return a.first < b.first; // 좌표 오름차순
    }
    return a.second < b.second; // 같지 않으면 색상 오름차순
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, idx, color, front, back, maxnum = 1000000001;
    long long ans = 0;
    cin >> n;

    if (n == 1) { cout << 0; return 0; }

    for (i = 0; i < n; i++) { // 입력
        cin >> idx >> color;
        v.push_back({idx, color});
    }

    sort(v.begin(), v.end(), compare); // 색상-좌표 오름차순 정렬

    for (i = 0; i < n; i++) {

        if (i == 0) { // 첫 번째 원소는 뒤만 검사
            if (v[i].second == v[i + 1].second) {
                ans += (v[i + 1].first - v[i].first);
            }
            continue;
        }

        if (i == n - 1) { // 마지막 원소는 앞만 검사
            if (v[i].second == v[i - 1].second) {
                ans += (v[i].first - v[i - 1].first);
            }
            break;
        }

        // 그 사이 원소들은 앞 뒤 검사 후 최솟값 저장
        if (v[i].second != v[i - 1].second && v[i].second != v[i + 1].second) {
            continue;
        }
        else {
            if (v[i].second == v[i - 1].second) {
                front = (v[i].first - v[i - 1].first);
            }
            else {
                front = maxnum;
            }

            if (v[i].second == v[i + 1].second) {
                back = (v[i + 1].first - v[i].first);
            }
            else {
                back = maxnum;
            }

            ans += min(front, back);
        }

    }

    cout << ans;

    return 0;
}