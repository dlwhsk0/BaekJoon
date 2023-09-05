#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// t �ð��� x�� ���������� �����ؾ� �ϴ� ����: t-x ����
// t-x�� key ������ ���� value(c)�� ���������ָ� ��

map<int, long long> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x, t;
    long long c, ans = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> t >> c; // ��ȣ, �ð�, �ݾ�
        m[t - x] += c;
    }

    for (auto iter: m) {
        ans = max(ans, iter.second);
    }
    cout << ans;

    return 0;
}