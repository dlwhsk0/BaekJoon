#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

// BFS

int map[101][101];
bool visited[101][101];
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, -1, 0, 1 };
int n, m, k, ans = 0;

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));
    int r = 0;

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        r++;
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];
            if ((nextY >= 0) && (nextY < n) && (nextX >= 0) && (nextX < n) && !visited[nextY][nextX] && (map[nextY][nextX] == 0)) {
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY, nextX));
            }
        }
    };

    return r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) { // 입력 받기
        for (int j = 0; j < n; j++) { cin >> map[i][j]; }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((map[i][j] == 0) && !visited[i][j]) {
                int r = bfs(i, j);
                if (r % k == 0) { ans += (r / k); }
                else { ans += ((r / k) + 1); }
            }
        }
    }

    if (ans >= 1) {
        if (m >= ans) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((map[i][j] == 0) && !visited[i][j]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
            cout << "POSSIBLE\n";
            cout << m - ans << '\n';
        }
        else { cout << "IMPOSSIBLE\n"; }
    }
    else { cout << "IMPOSSIBLE\n"; }

    return 0;
}