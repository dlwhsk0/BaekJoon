#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �׷��� Ž�� DFS https://scarlettb.tistory.com/94

int N, M;
int hacked = 1; // ��ŷ ������ ��ǻ�� ��
vector<pair<int, int>> v; // <��ǻ�� ��ȣ, ��ŷ ������ ��ǻ�� ��>
vector<int> map[10001];
bool visited[10001];

void DFS(int v) {
    visited[v] = true;

    for (int w = 0; w < map[v].size(); w++) {
        int nv = map[v][w];

        if (visited[nv] == 0) { // �湮�ߴ��� �˻�
            visited[nv] = true;
            DFS(nv);
            hacked++;
        }
    }
}

void resetVisit() {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int maxHack = -1;

    cin >> N >> M;
    for (int i = 0; i < M; i++) { // �Է� �ޱ�
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) { // Ž�� ����
        DFS(i);
        resetVisit();
        v.push_back(make_pair(i, hacked));
        hacked = 1;
    }

    for (int i = 0; i < v.size(); i++) { // ��ŷ ������ �ִ� ��ǻ�� �� 
        if (v[i].second > maxHack) {
            maxHack = v[i].second;
        }
    }

    for (int i = 0; i < v.size(); i++) { // ��ǻ�� ��ȣ ���
        if (v[i].second == maxHack) {
            cout << v[i].first << " ";
        }
    }
}
