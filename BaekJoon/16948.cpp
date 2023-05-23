#include <iostream>
#include <queue>
using namespace std;

/*
�ʺ� �켱 Ž���� ���� �ִ� ��� ���ϱ�
*/

int n;
int path[201][201];
bool visit[201][201]; // �湮 ���� ����
queue<pair<int, int>> q;

int dx[] = { -2,-2,0,0,2,2 }; // ���� ����Ʈ �̵����
int dy[] = { -1,1,-2,2,-1,1 };

void BFS(int x, int y) { // �ʺ� �켱 Ž��
    path[x][y] = 0;
    visit[x][y] = true; // �湮 ó��
    q.push(make_pair(x, y));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop(); // �湮�� ���� ť���� ����

        for (int i = 0; i < 6; i++) { // �̵� �������� �˻�
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > n || ny > n) { continue; }
            if (!visit[nx][ny]) { // �湮���� �ʾ��� ��
                visit[nx][ny] = true;
                path[nx][ny] = path[x][y] + 1; // �̵� Ƚ�� ����
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n;

    int r1, c1, r2, c2; // ó�� ��ġ, ���� ��ġ
    cin >> r1 >> c1 >> r2 >> c2;

    BFS(r1, c1); // �ʺ� �켱 Ž�� ����

    if (path[r2][c2] == 0) { cout << -1; }
    else { cout << path[r2][c2]; }

    return 0;
}
