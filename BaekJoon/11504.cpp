#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

// ��� �κк��� �����ϸ� �� ��

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, n, m, cnt;
    char num;
    string x, y, ans;

    cin >> t;
    for (int i = 0; i < t; i++) {
        x = ""; y = ""; cnt = 0;
        cin >> n >> m; // ������ ĭ, ���� �ڸ���
        vector<char> v(n);

        for (int k = m; k > 0; k--) { // x �Է�
            cin >> num;
            x += num;
        }
        for (int k = m; k > 0; k--) { // y �Է�
            cin >> num;
            y += num;
        }
        for (int k = 0; k < n; k++) { cin >> v[k]; } // ������

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