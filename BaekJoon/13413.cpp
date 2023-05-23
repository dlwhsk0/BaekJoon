#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

/*
������ �� 2�� ü����
�� �ϳ� ���� ü����

�ּ� Ƚ��:
��ǥ�� �ٸ� ���¸� B, W ��츦 ������ ����
�տ��� B, W�� ���� ���� ���� (��ȯ�� �� ����)
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, n, i, j, B, W, answer;
    bool flag = 1; // 1: B, 0: W
    string start, goal;

    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        cin >> start;
        cin >> goal;

        B = 0; W = 0;
        for (j = 0; j < n; j++) {
            if (start[j] != goal[j]) {
                if (start[j] == 'B') { B++; }
                else { W++; }
            }
        }

        answer = B + W - min(B, W);
        cout << answer << '\n';
    }

    return 0;
}
