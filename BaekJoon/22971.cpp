#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) { cin >> v[i]; }

    vector<long long> dp(n, 1); // 1로 초기화
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i; k++) {
            if (v[k] < v[i]) { dp[i] = (dp[i] + dp[k]) % 998244353; }
        }
    }

    for (int i = 0; i < n; i++) { cout << dp[i] << " "; }

    return 0;
}