#include <iostream>

using namespace std;

/*
1. max ���ϱ�
2. ��� ������ ����/max*100�� �ٲٱ�
3. ���ο� ��� ���ϱ�
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    float arr[1000] = { 0 };
    int n, i;
    float max = 0, avg = 0;
    cin >> n; // ���� ����

    for (i = 0; i < n; i++) {
        cin >> arr[i]; // �Է�

        if (max < arr[i]) { max = arr[i]; } // max
    }

    for (i = 0; i < n; i++) {
        avg += (arr[i] / max) * 100;
    }
    cout << avg / n;

    return 0;
}
