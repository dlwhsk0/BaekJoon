#include <iostream>
using namespace std;

/*
* �Ϸ簡 ���� ������ �߷��� k ��ŭ �����Ѵ�.
* N ���� � ŰƮ�� N �� ���� �� ������ ����� �� �ִ�.
* 
* DFS ��Ʈ��ŷ
* >> ;; int�� ���������� �ϸ� �� ��
*/

int exercise[51];
bool visited[51];
int weight = 500, k, n, ans = 0;

void DFS(int dep) {
    if (dep == n) { ans++; } // ������ ������ 1 ����
    else {
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                if (weight + exercise[i] >= 500) {
                    weight += exercise[i];

                    DFS(dep + 1);
                    weight -= exercise[i]; // ��
                }
                visited[i] = false; // �湮 ���� �ʱ�ȭ
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> exercise[i];
        visited[i] = false;
        exercise[i] -= k; // ������ - �Ϸ� ���ҷ� = ���� ������
    }

    DFS(0);
    cout << ans;

    return 0;
}