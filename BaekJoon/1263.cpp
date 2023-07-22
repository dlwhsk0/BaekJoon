#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) { // 정렬 함수
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t, s, tmp = 0, left = 0;
    cin >> n;

    vector<pair<int, int>> v(n); // 끝내야할 시간, 소요 시간
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        v.push_back({ t, s });
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            if (v[i].second >= tmp) {
                left += v[i].second - tmp;
            }
            else if (tmp - v[i].second >= left) { left = 0; }
            else if (tmp - v[i].second < left) { left -= tmp - v[i].second; }
        }
        tmp = v[i].second - v[i].first;
    }

    if (left > 0) { tmp -= left; }

    if (tmp < 0) { cout << -1; }
    else { cout << tmp; }

    return 0;
}