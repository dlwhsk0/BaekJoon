#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int n, m;
string ans;
string arr[101];

bool dfs(int x, int y, int cnt, int d) { // 각 방향을 검사
    if (cnt == ans.size()) return true;
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) { return false; }
    bool flag = false;

    if (arr[nx][ny] == ans[cnt]) { flag = dfs(nx, ny, cnt + 1, d); }
    return flag;
}

bool search(int x, int y) { // 위 아래 오른쪽 왼쪽 대각선 4방향 검사
    for (int i = 0; i < 8; i++) { if (dfs(x, y, 1, i)) { return true; } }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> ans;
    cin >> n >> m;

    for (int i = 0; i < n; i++) { cin >> arr[i]; } // 입력 받기

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (arr[i][k] == ans[0]) { // 첫 글자가 같은 경우 탐색 시작
                if (search(i, k)) { cout << 1; return 0; } // 찾음
            }
        }
    }
    
    cout << 0; // 끝까지 못 찾음
    return 0;
}