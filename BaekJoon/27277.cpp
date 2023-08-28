#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

// 손해를 최소화 하기 위해 0이 되는 숫자를 최대한 작은 수로 만들어야 함
// (작은 값, 큰 값) 쌍으로 만들고 스택에 넣기
// 쌍에서 앞은 무조건 0이 됨, => 큰 값 - 작은 값이 됨

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, num, a, b;
    long long ans = 0;
    cin >> n;

    if (n == 1) { // 1명이면 바로 출력 후 종료
        cin >> num;
        cout << num;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end()); // 오름차순 정렬

    for (int i = 0; i < n / 2; i++) {
        ans += (v[n - 1 - i] - v[i]);
    }

    if (n % 2) { ans += v[n / 2]; } // 첫번째 숫자 더하기
    else { ans += v[n / 2 - 1]; }

    cout << ans;

    return 0;
}