#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
�� ���� - ���� �����ϴ� �� ����� ����
�󵵰� ���ٸ� ���� ���� ���� ��

�� ���� map�� �̿��Ͽ� ����
*/

map<int, int> od; // ���ڿ� ����

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) { // �󵵰� ���ٸ�
        return od[a.first] < od[b.first]; // ���� ���� ���� ��
    }
    else {
        return a.second > b.second; // �� ��
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, c, num, i; // �޽��� ����, ���� �۰ų� ����
    cin >> n >> c;

    map<int, int> m; // ���ڿ� ��
    for (i = 0; i < n; i++) {
        cin >> num;
        m[num]++;

        if (od[num] == 0) { od[num] = i + 1; } // ���� ����
    }

    // value ������ �����ϱ����� ���ͷ� �̵�
    vector<pair<int, int>> vec(m.begin(), m.end());

    sort(vec.begin(), vec.end(), cmp);

    for (auto v : vec) { // ���
        for (i = 0; i < v.second; i++) { // �󵵼�(����)��ŭ ���
            cout << v.first << " ";
        }
    }

    return 0;
}
