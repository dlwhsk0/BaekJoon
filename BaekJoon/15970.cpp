#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
** ���� �� �� ������ ���� ���� �� ª�� ���� ����
1) if ù��° ����: answer += v[i+1] - v[i];
2) else if ������ ����: { answer += v[i] - v[i - 1]; }
3) else: answer += min(v[i+1] - v[i], v[i] - v[i-1]);

1��° �õ�: 31�� ?? ����? --> ���� ��� �ΰ��� �ִ°� �ƴϾ���!

2���� �迭 [����][����]
���� ���� Ž��
1) ���� ���� ���� �˻� ������ continue
2) ** ���� �� �� ������ ���� ���� �� ª�� ���� ����
*/

vector<int> v[5000];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, num, color, i, j, size;
    long long answer = 0;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num >> color;
        v[color].push_back(num);
    }

    for (i = 0; i < 5000; i++) { // ���� ���� �˻�
        if (v[i].empty()) { continue; }

        sort(v[i].begin(), v[i].end()); // ����

        size = v[i].size() - 1;
        answer += (v[i][1] - v[i][0]) + (v[i][size] - v[i][size-1]);

        for (j = 1; j < size; j++) { answer += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]); }
    }
    
    cout << answer;

    return 0;
}