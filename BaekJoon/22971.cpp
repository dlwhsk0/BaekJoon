#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �ִ�: �뷮 �� �ִ�
// ���� ������ ģ������ ������ ������ �뷮�� ���̰�
// ũ�ų� ������ ���� ���Ž�Ų �� ũ�� �뷮�� ������Ų��.

int arr[10001];
int n, k, ans;

void binary_search(int start, int end) {
    if (start > end) { return; }
    int cnt = 0, mid = (start + end) / 2;

    for (int i = 0; i < n; i++) { cnt += arr[i] / mid; } // ���� ����

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