#include <iostream>
using namespace std;

int dpMin[10001]; // �ּڰ�
int dpMax[10001]; // �ִ�

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a = 1, b = 2; // �Ǻ���ġ�� 3,4��° ��
    cin >> n;

    for (int i = 1; i <= n; i++) { dpMin[i] = 1e9; } // �ִ밪 �־��ֱ�

    while (b <= n) {
        for (int i = b; i <= n; i++) {
            dpMin[i] = min(dpMin[i], dpMin[i - b] + a);
            dpMax[i] = max(dpMax[i], dpMax[i - b] + a);
        }
        b += a; // �Ǻ���ġ ������ ���� ���� �ٲ��ֱ�
        a = b - a;
    }
    cout << dpMin[n] << " " << dpMax[n];

    return 0;
}
