#include <iostream>
#include <queue>
using namespace std;

/*
너비 우선 탐색을 통해 최단 경로 구하기
*/

int n;
int path[201][201];
bool visit[201][201]; // 방문 여부 저장
queue<pair<int, int>> q;

int dx[] = { -2,-2,0,0,2,2 }; // 데스 나이트 이동방법
int dy[] = { -1,1,-2,2,-1,1 };

void BFS(int x, int y) { // 너비 우선 탐색
    path[x][y] = 0;
    visit[x][y] = true; // 방문 처리
    q.push(make_pair(x, y));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop(); // 방문한 곳은 큐에서 삭제

        for (int i = 0; i < 6; i++) { // 이동 가능한지 검사
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > n || ny > n) { continue; }
            if (!visit[nx][ny]) { // 방문하지 않았을 때
                visit[nx][ny] = true;
                path[nx][ny] = path[x][y] + 1; // 이동 횟수 증가
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n;

    int r1, c1, r2, c2; // 처음 위치, 나중 위치
    cin >> r1 >> c1 >> r2 >> c2;

    BFS(r1, c1); // 너비 우선 탐색 실행

    if (path[r2][c2] == 0) { cout << -1; }
    else { cout << path[r2][c2]; }

    return 0;
}
