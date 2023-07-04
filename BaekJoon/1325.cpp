#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 그래프 탐색 DFS https://scarlettb.tistory.com/94

int N, M;
int hacked = 1; // 해킹 가능한 컴퓨터 수
vector<pair<int, int>> v; // <컴퓨터 번호, 해킹 가능한 컴퓨터 수>
vector<int> map[10001];
bool visited[10001];

void DFS(int v) {
    visited[v] = true;

    for (int w = 0; w < map[v].size(); w++) {
        int nv = map[v][w];

        if (visited[nv] == 0) { // 방문했는지 검사
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
    for (int i = 0; i < M; i++) { // 입력 받기
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) { // 탐색 진행
        DFS(i);
        resetVisit();
        v.push_back(make_pair(i, hacked));
        hacked = 1;
    }

    for (int i = 0; i < v.size(); i++) { // 해킹 가능한 최대 컴퓨터 수 
        if (v[i].second > maxHack) {
            maxHack = v[i].second;
        }
    }

    for (int i = 0; i < v.size(); i++) { // 컴퓨터 번호 출력
        if (v[i].second == maxHack) {
            cout << v[i].first << " ";
        }
    }
}
