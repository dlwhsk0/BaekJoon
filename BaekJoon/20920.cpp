#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*
��, ����, ���ĺ�
map�� �⺻ ��������

map�� value ������ �����ϱ�
1. map�� vector�� �̵�
2. vector�� second�������� ����
*/

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) { // �󵵰� ���� ���
        if (a.first.size() == b.first.size()) {
            return a.first < b.first; // �������� 
        }
        else {
            return a.first.size() > b.first.size();
        }
    }
    else {
        return a.second > b.second;
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    map <string, int> mp; // �ܾ�� �󵵰� ����� map
    string str;
    int n, m, i; // �ܾ� ����, �ϱ� ����
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> str;

        if (str.length() >= m) { // m �̻� ���̸� map�� ����
            if (mp.find(str) == mp.end()) { mp[str] = 1; }
            else { mp[str]++; }
        }
    }

    vector<pair<string, int>> vec(mp.begin(), mp.end()); // map�� vector�� �̵�

    sort(vec.begin(), vec.end(), cmp);

    for (auto iter : vec) {
        cout << iter.first << '\n';
    }

    return 0;
}