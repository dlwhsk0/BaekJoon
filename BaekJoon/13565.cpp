#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
0: 전류 통함 1: 전류 안 통함(방문함)

1. DFS로 연결된 모든 흰색을 방문한다
2. 깊이 우선 탐색을 반복하다 안쪽 격자에 방문하면 성공

시간 복잡도: ??????????
*/

int n, m, ny, nx;
string map[1000];
bool flag = false;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 }; // 상, 하, 좌, 우

void DFS(int y, int x) {
    map[y][x] = '1'; // 방문함
    if(y == m-1) { flag = true; return; } // 안쪽 격자 방문

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i]; // 상하좌우

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) { continue; }
        if (map[ny][nx] == '0') { DFS(ny, nx); }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 0; i < m; i++) { cin >> map[i]; } // 격자 입력받기

    for (int i = 0; i < n; i++) {
        if (map[0][i] == '0') {
            DFS(0, i);

            if (flag) { cout << "YES"; return 0; }
        }
    }
    
    if (flag) { cout << "YES"; }
    else { cout << "NO"; }

    return 0;
}