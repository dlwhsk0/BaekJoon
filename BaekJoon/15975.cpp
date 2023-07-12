#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1. ���� 2. ��ǥ ������ �������� ����
// ������ �� �Ÿ��� ���ؼ� �ּڰ� ����

vector<pair<int, int>> v; // ��ǥ, ����

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) { // ������ ���ٸ�
        return a.first < b.first; // ��ǥ ��������
    }
    return a.second < b.second; // ���� ������ ���� ��������
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, idx, color, front, back, maxnum = 1000000001;
    long long ans = 0;
    cin >> n;

    if (n == 1) { cout << 0; return 0; }

    for (i = 0; i < n; i++) { // �Է�
        cin >> idx >> color;
        v.push_back({idx, color});
    }

    sort(v.begin(), v.end(), compare); // ����-��ǥ �������� ����

    for (i = 0; i < n; i++) {

        if (i == 0) { // ù ��° ���Ҵ� �ڸ� �˻�
            if (v[i].second == v[i + 1].second) {
                ans += (v[i + 1].first - v[i].first);
            }
            continue;
        }

        if (i == n - 1) { // ������ ���Ҵ� �ո� �˻�
            if (v[i].second == v[i - 1].second) {
                ans += (v[i].first - v[i - 1].first);
            }
            break;
        }

        // �� ���� ���ҵ��� �� �� �˻� �� �ּڰ� ����
        if (v[i].second != v[i - 1].second && v[i].second != v[i + 1].second) {
            continue;
        }
        else {
            if (v[i].second == v[i - 1].second) {
                front = (v[i].first - v[i - 1].first);
            }
            else {
                front = maxnum;
            }

            if (v[i].second == v[i + 1].second) {
                back = (v[i + 1].first - v[i].first);
            }
            else {
                back = maxnum;
            }

            ans += min(front, back);
        }

    }

    cout << ans;

    return 0;
}