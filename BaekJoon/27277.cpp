#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

// ���ظ� �ּ�ȭ �ϱ� ���� 0�� �Ǵ� ���ڸ� �ִ��� ���� ���� ������ ��
// (���� ��, ū ��) ������ ����� ���ÿ� �ֱ�
// �ֿ��� ���� ������ 0�� ��, => ū �� - ���� ���� ��

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, num, a, b;
    long long ans = 0;
    cin >> n;

    if (n == 1) { // 1���̸� �ٷ� ��� �� ����
        cin >> num;
        cout << num;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end()); // �������� ����

    for (int i = 0; i < n / 2; i++) {
        ans += (v[n - 1 - i] - v[i]);
    }

    if (n % 2) { ans += v[n / 2]; } // ù��° ���� ���ϱ�
    else { ans += v[n / 2 - 1]; }

    cout << ans;

    return 0;
}