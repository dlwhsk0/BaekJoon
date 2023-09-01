#include <iostream>
#include <algorithm>
using namespace std;

// 대칭이어야 함

int dp[100001];
int t, n, maxn = 1000000009;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    for (int i = 6; i <= 100000; i++) {
        dp[i] = ((dp[i - 2] + dp[i - 4]) % maxn + dp[i - 6]) % maxn;
    }

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}