#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 1 0
// 0 1
// ���� ���� ��찡 ������ NO

vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    v.resize(n);
    for (int i = 0; i < n; i++) { // ���� �Է�
        v[i].resize(m);
        for (auto& k : v[i]) cin >> k;
    }
    sort(v.begin(), v.end()); // �������� ���� (�ָ� �ִ� ������ ����)

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (v[i - 1][k] > v[i][k]) { // �� ���� ������� �� �ָ� �ִ� ����� ���� ���
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}