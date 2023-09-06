#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 1 0
// 0 1
// 위와 같은 경우가 있으면 NO

vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    v.resize(n);
    for (int i = 0; i < n; i++) { // 여부 입력
        v[i].resize(m);
        for (auto& k : v[i]) cin >> k;
    }
    sort(v.begin(), v.end()); // 오름차순 정렬 (멀리 있는 순으로 정렬)

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (v[i - 1][k] > v[i][k]) { // 못 들은 사람보다 더 멀리 있는 사람이 들은 경우
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}