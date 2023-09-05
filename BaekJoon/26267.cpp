#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// t 시간에 x에 서있으려면 시작해야 하는 지점: t-x 지점
// t-x를 key 값으로 곳에 value(c)를 누적시켜주면 됨

map<int, long long> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x, t;
    long long c, ans = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> t >> c; // 번호, 시간, 금액
        m[t - x] += c;
    }

    for (auto iter: m) {
        ans = max(ans, iter.second);
    }
    cout << ans;

    return 0;
}