#include <iostream>
using namespace std;

/*
�ִ� ������ �ι�° ���ڸ� ���ؼ� �������� �ٽ� ���

numcnt �Լ��� ���� ���ϱ�
*/

int numcnt(int prev, int num) {
    int next = prev - num;
    if (next < 0) return 2; // 2��° ������
    return numcnt(num, next) + 1;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, sec, count, max = 0, answer;
    cin >> n;

    for (i = 1; i <= n; i++) {
        count = numcnt(n, i);

        if (count > max) {
            max = count;
            sec = i;
        }
    }

    cout << max << '\n';
    cout << n << " " << sec;

    int temp = n - sec;
    while (temp >= 0) {
        n = sec;
        sec = temp;
        cout << " " << sec;
        temp = n - sec;
    }

    return 0;
}
