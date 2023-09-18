#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

// 어느 부분부터 시작하면 될 지

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, n, m, cnt;
    char num;
    string x, y, ans;

    cin >> t;
    for (int i = 0; i < t; i++) {
        x = ""; y = ""; cnt = 0;
        cin >> n >> m; // 돌림판 칸, 숫자 자릿수
        vector<char> v(n);

        for (int k = m; k > 0; k--) { // x 입력
            cin >> num;
            x += num;
        }
        for (int k = m; k > 0; k--) { // y 입력
            cin >> num;
            y += num;
        }
        for (int k = 0; k < n; k++) { cin >> v[k]; } // 돌림판

        for (int k = 0; k < n; k++) {
            ans = "";
            if (v[k] >= x[0] && v[k] <= y[0]) {
                for (int z = 0; z < m; z++) { ans += v[(k + z + n) % n]; }
                if (stoi(ans) >= stoi(x) && stoi(ans) <= stoi(y)) { cnt++; }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}