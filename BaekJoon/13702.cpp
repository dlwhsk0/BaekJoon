#include <iostream>
#include <algorithm>
using namespace std;

// ���� ������ ģ������ ������ ������ �뷮�� ���̰�
// ũ�ų� ������ ���� ���Ž�Ų �� �뷮�� ������Ų��.
// ���ɸ��� �뷮�� 2^31 -1 ���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.
// �� int �� ���� �ȿ� ������ �̺�Ž�� �������� ������ �����÷ΰ� �߻��� �� �ִ�.

int arr[10001];
int n, k;
long long ans;

void binary_search(long long start, long long end) {
    if (start > end) { return; }
    int cnt = 0;
    long long mid = (start + end) / 2;
    cout << "***mid: " << mid << '\n';


    for (int i = 0; i < n; i++) { cnt += arr[i] / mid; } // ���� ����

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
        num = max(num, arr[i]); // �ִ�
    }
    cout << "***num: " << num << '\n';


    binary_search(1, num);

    cout << ans;

    return 0;
}