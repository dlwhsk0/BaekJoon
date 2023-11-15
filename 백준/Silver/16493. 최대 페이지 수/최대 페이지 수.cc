#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

int dp[21][201]; // 챕터 수, 남은 기간
int dates[21]; // 챕터의 소요일 수 weight
int pages[21]; // 챕터의 페이지 수 value

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; // 남은 기간, 챕터 수

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> dates[i] >> pages[i];

        for (int j = 1; j <= n; j++) {
            if (j - dates[i] >= 0) { dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - dates[i]] + pages[i])); }
            else { dp[i][j] = dp[i - 1][j]; }
        }
    }

    cout << dp[m][n];

    return 0;
}