#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 최대: 용량 중 최댓값
// 나눈 총합이 친구들의 수보다 작으면 용량을 줄이고
// 크거나 같으면 답을 갱신시킨 후 크면 용량을 증가시킨다.

int arr[10001];
int n, k, ans;

void binary_search(int start, int end) {
    if (start > end) { return; }
    int cnt = 0, mid = (start + end) / 2;

    for (int i = 0; i < n; i++) { cnt += arr[i] / mid; } // 나눈 총합

    if (cnt < k) { return binary_search(start, mid - 1); }
    else {
        ans = mid;
        if (cnt > k) { return binary_search(mid + 1, end); }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        num = max(num, arr[i]);
    }

    binary_search(1, num);

    cout << ans;

    return 0;
}