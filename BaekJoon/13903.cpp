#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
DFS 일 것 같았는데 BFS라네
*/

struct block {
    int x, y;
};

int r, c, n;
int blocks[1000][1000]; // 보도블럭
int dist[1000][1000]; // 거리
int dx[10], dy[10]; // 이동 규칙
queue<block> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop(); // 큐에서 삭제

        if (x == r - 1) {
            cout << dist[x][y] << '\n';
            return;
        }

        for (int i = 0; i < n; i++) {
            int nx = x + dx[i], ny = y + dy[i]; // 이동한 곳

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) { continue; } // 범위 밖
            
            if (dist[nx][ny] == -1 && blocks[nx][ny]) { // 큐에 삽입하고 걸음 횟수를 축적한다
                q.push({ nx, ny });
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    cout << "-1";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> blocks[i][j];
            dist[i][j] = -1;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) { cin >> dx[i] >> dy[i]; }

    for (int i = 0; i < c; i++) { // 0번째 세로 블록을 큐에 삽입
        if (blocks[0][i]) {
            q.push({ 0, i });
            dist[0][i] = 0;
        }
    }
    bfs();

    return 0;
}
