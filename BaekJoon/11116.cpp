#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// t 있고 +500이 있으면 +1000 과 +1500이 right에 있는지 검사

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, t, cnt;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m; cnt = 0;
        vector<int> left(m); vector<int> right(m);
        for (int k = 0; k < m; k++) { cin >> left[k]; }
        for (int k = 0; k < m; k++) { cin >> right[k]; }

        for (int k = 0; k < m; k++) {
            t = left[k];
            if (find(left.begin(), left.end(), t + 500) != left.end()) {
                if (find(right.begin(), right.end(), t + 1000) != right.end()) {
                    if (find(right.begin(), right.end(), t + 1500) != right.end()) { cnt++; }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}