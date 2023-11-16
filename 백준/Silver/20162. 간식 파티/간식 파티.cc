#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

int dp[1001];
int snack[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> snack[i];
        dp[i] = snack[i];
        for (int j = 1; j < i; j++) {
            if (snack[j] < snack[i]) { dp[i] = max(dp[i], dp[j] + snack[i]); }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}