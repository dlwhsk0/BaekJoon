#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
int n, i, k;
long long a, ans = 0;
bool flag;

// ó�� �� a �ְ� �� �����ٰ� �Ȱ����� ������(0 ����) �װ� 0���� ����� a�� �ι�� �ٲ�
// �ٽ� ó������ ���ƿͼ� ������
// a�� �������������� �׶� ����

void number() {
    for (i = 0; i < n; i++) {
        if (v[i] != 0) {
            cout << "* " << i << ": " << v[i] << '\n';
            for (k = 0; k < n; k++) {
                if (k != i && v[k] == v[i]) {
                    cout << "*** " << k << ": " << v[k] << '\n';
                    v[i] *= 2;
                    v[k] = 0;
                    flag = true;
                    for (long long a : v) { cout << a << " "; }
                    cout << '\n';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) { // �Է�
        cin >> a;
        if (a != 0) { v.push_back(a); } // 0�� �ƴ� ��쿡�� ����
    }

    for (long long a : v) { cout << a << " "; }
    cout << '\n';

    n = (int)v.size();
    flag = true;

    while (flag) {
        flag = false;
        number();
        cout << "���� flag��?: " << flag << '\n';
    }

    for (long long a : v) { ans = max(a, ans); }

    cout << ans;

    return 0;
}