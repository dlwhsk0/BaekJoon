#include <iostream>
using namespace std;

int n, ny, nx, ans = 987654321;
int graph[11][11];
int visited[11][11]; // 방문 처리
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 브루트포스

void go(int y, int x, int depth, int cost) { // 좌표, 깊이, 비용
	if (depth == 3) { // 3개까지 심을 수 있음
		ans = min(ans, cost);
		return;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool ok = true;
			if (visited[i][j]) continue;

			for (int d = 0; d < 4; d++) {
				ny = i + dy[d];
				nx = j + dx[d];

				if (ny < 1 || ny > n || nx < 1 || nx > n || visited[ny][nx]) {
					ok = false;  break;
				}
			}
			if (ok) {
				int tmp = graph[i][j];
				for (int d = 0; d < 4; d++) {
					ny = i + dy[d]; nx = j + dx[d];
					visited[ny][nx] = 1;
					tmp += graph[ny][nx];
				}

				visited[ny][nx] = 1;
				go(ny, nx, depth + 1, cost + tmp);

				for (int d = 0; d < 4; d++) {
					ny = i + dy[d]; nx = j + dx[d];
					visited[ny][nx] = 0;
				}
				visited[ny][nx] = 0;
			}
		}
	}
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> graph[i][j];
	}

	go(1, 1, 0, 0);
	cout << ans;

    return 0;
}