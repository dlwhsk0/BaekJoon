#include <iostream>

using namespace std;

// ������ü �ڽ��� aaa ũ���� ������ü �ڽ��� ��� �ֱ� ���� a �ִ�

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, l, w, h;
    double L = 0, R = 1000000000, M;

    cin >> n >> l >> w >> h;

    for (int i = 0; i < 10000; i++) { // �̺� Ž��
        M = (L + R) / 2;

        if ((long long)(l / M) * (long long)(w / M) * (long long)(h / M) < n) { R = M; }
        else { L = M; }
    }

    printf("%.10f", L);

    return 0;
}
