#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

vector<pair<int, int>> g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, v, t;
    ll cost, tmp, tc;

    cin >> n;
    g.resize(n); // 초기화

    for (int i = 0; i < n; i++) { // f, c 입력
        cin >> v >> t;
        g[i] = { v, t };
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> v >> t;
        cost = -1; // 초기화

        for (int k = 1; k < (1 << n); k++) {
            tmp = 0; tc = 0; // 초기화

            for (int z = 0; z < n; z++) {
                if (k & (1 << z)) {
                    tmp += g[z].first;
                    tc += g[z].second;
                }
            }
            if (t >= (v / tmp) + (v % tmp != 0)) {
                if (cost == -1 || cost > tc) { cost = tc; }
            }
        }
        cout << "Case " << i << ": " << (cost == -1 ? "IMPOSSIBLE" : to_string(cost)) << '\n';
    }

    return 0;
}