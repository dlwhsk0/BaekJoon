#include <iostream>
#include <algorithm>
using namespace std;

// 나눈 총합이 친구들의 수보다 작으면 용량을 줄이고
// 크거나 같으면 답을 갱신시킨 후 용량을 증가시킨다.
// 막걸리의 용량은 2^31 -1 보다 작거나 같은 자연수 또는 0이다.
// ㄴ int 형 범위 안에 들지만 이분탐색 과정에서 변수에 오버플로가 발생할 수 있다.

int arr[10001];
int n, k;
long long ans;

void binary_search(long long start, long long end) {
    if (start > end) { return; }
    int cnt = 0;
    long long mid = (start + end) / 2;
    cout << "***mid: " << mid << '\n';


    for (int i = 0; i < n; i++) { cnt += arr[i] / mid; } // 나눈 총합

    cout << "***cnt: " << cnt << '\n';
    if (cnt < k) { return binary_search(start, mid - 1); }
    else {
        ans = mid;
        return binary_search(mid + 1, end);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        num = max(num, arr[i]); // 최댓값
    }
    cout << "***num: " << num << '\n';


    binary_search(1, num);

    cout << ans;

    return 0;
}