#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

// 기존의 피보나치 수열과 절댓값이 같지만 짝수인 경우 음수 부호가 추가됨 

ll arr[1000001];
ll num = 1000000000;

int dp(int n) {
    arr[0] = 0; arr[1] = 1;

    for (int i = 2; i <= n; i++) { arr[i] = (arr[i - 1] + arr[i - 2]) % num; }

    return arr[n] % num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, flag = 1, ans;
    cin >> n;

    if (n < 0) {
        n *= -1;
        if (n % 2 == 0) { flag = -1; }
    }
    ans = dp(n);

    if (ans == 0) { cout << 0 << '\n'; }
    else { cout << flag << '\n'; }
    cout << ans;

    return 0;
}