#include <iostream>
#include <unordered_map> // ���� ���� map (�ؽ� ��)
#include <vector>
#include <algorithm>
using namespace std;

/*
�����ϸ� ����, ������ ����
*/

unordered_map<string, int> um; // key: �й� value: ��ȣ
vector<pair<string, int>> v; // value ���� ���� ����

bool compare(const pair<string, int>& a, const pair<string, int>& b) { // value�� ����
	return a.second < b.second;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k, l, i;
	string str;
	cin >> k >> l; // ���������ο�, ����ϱ���

	for (i = 0; i < l; i++) { // �Է�
		cin >> str;
		um[str] = i;
	}

	for (auto& i : um) { v.push_back(i); } // ���� ����

	sort(v.begin(), v.end(), compare);
	for (i = 0; i < min(k, (int)v.size()); i++) { cout << v[i].first << '\n'; }

	return 0;
}