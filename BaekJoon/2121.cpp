#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/*
�� ���� (x, y)�� ���
(x+a, y) / (x, y+b) / (x+a, y+b)
�̷��� 3���� �����ϸ� ���簢���� �ϼ��ȴ�.

set �����̳� <set>
1. �ߺ��� ���ش�
2. ������ ������� ���ĵǾ� �Էµȴ�.
3. �ε����� ������ �� ����...
*/

set<pair<int, int>> s;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b, x, y, i, j, ans=0;
    cin >> n;
    cin >> a >> b;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
        s.insert({x, y});
    }

    for (i = 0; i < n; i++) {
        x = v[i].first;
        y = v[i].second;

        if (s.find({ x + a, y }) != s.end() && s.find({ x + a, y + b }) != s.end() && s.find({ x, y + b }) != s.end()) { ans++; }
    }
    cout << ans;

    return 0;
}