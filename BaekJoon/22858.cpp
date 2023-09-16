#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ������ �� ���� ����
// ���� ��Ģ�� ���ִ� ���ڷ� ī�� ��ġ�� �Ű��ָ� �ȴ�!

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second; // second�� �������� ����
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, num;
    cin >> n >> k; //���� ����, ���� Ƚ��

    vector<pair<int, int>> v(n); // ����, ����
    vector<int> d(n); // ���� ��Ģ

    for (int i = 0; i < n; i++) {
        cin >> num;
        v[i] = { num, i + 1 };
    }
    for (int i = 0; i < n; i++) { cin >> d[i]; }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) { v[j].second = d[j]; }
        sort(v.begin(), v.end(), compare);
    }

    for (int i = 0; i < n; i++) { cout << v[i].first << " "; }

    return 0;
}