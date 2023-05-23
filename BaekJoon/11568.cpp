#include <iostream>
using namespace std;

/*
dp 사용
LIS 최장 증가 부분 수열: 가장 긴 증가하는 부분 수열 구하기

모든 원소와 그 원소 이전의 숫자들을 검사
if 현재 숫자가 이전 숫자보다 크다 && 현재 숫자 dp가 이전 숫자 dp+1보다 작다:
    현재 숫자 dp = 이전 숫자 dp + 1 갱신

위 과정을 거치면 dp중 가장 큰 값이 lis의 길이가 된다
*/

int card[1000];
int dp[1000];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, j, lis = 0;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> card[i];
        dp[i] = 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (card[i] > card[j] && dp[i] < (dp[j] + 1)) { dp[i] = dp[j] + 1; }
        }
    }

    for (i = 0; i < n; i++) { lis = max(lis, dp[i]); }
    cout << lis;


    return 0;
}