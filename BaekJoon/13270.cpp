#include <iostream>
using namespace std;

int dpMin[10001]; // 최솟값
int dpMax[10001]; // 최댓값

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a = 1, b = 2; // 피보나치의 3,4번째 수
    cin >> n;

    for (int i = 1; i <= n; i++) { dpMin[i] = 1e9; } // 최대값 넣어주기

    while (b <= n) {
        for (int i = b; i <= n; i++) {
            dpMin[i] = min(dpMin[i], dpMin[i - b] + a);
            dpMax[i] = max(dpMax[i], dpMax[i - b] + a);
        }
        b += a; // 피보나치 수열의 다음 수로 바꿔주기
        a = b - a;
    }
    cout << dpMin[n] << " " << dpMax[n];

    return 0;
}
