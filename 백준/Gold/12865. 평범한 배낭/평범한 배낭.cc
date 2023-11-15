#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

int dp[101][100001]; // 물품 번호, 제한 무게
int weight[101]; // 물건의 무게
int value[101]; // 물건의 가치

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;

    cin >> n >> k; // 물품의 수, 제한 무게

    for (int i = 1; i <= n; i++) {
            cin >> weight[i] >> value[i]; // 물건의 무게, 가치
        for (int j = 1; j <= k; j++) {
            // 제한 무게보다 크면 넣지 않는다
            if (weight[i] > j) { dp[i][j] = dp[i-1][j]; }
            // 이전에 제한 무게에서 현재 물건의 무게만큼 뺀 경우의 가치와 비교해 max값을 선택한다
            else { dp[i][j] = max(dp[i - 1][j], (dp[i-1][j - weight[i]] + value[i])); }
        }
    }

    cout << dp[n][k];

    return 0;
}