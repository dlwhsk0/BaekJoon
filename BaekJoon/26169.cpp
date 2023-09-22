#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

// 세 번 이하의 이동으로 먹어야 함 깊이 3의 dfs

int mx[4] = { 0, 1, -1, 0 };
int my[4] = { 1, 0, 0, -1 };
vector<vector<int>> board;
vector<vector<int>> cost;
bool ans;

struct val {
    int cost;
    int depth;
};

void dfs(int x, int y, int d) {
    int temp = board[x][y];
    if (d == 3) {
        if (cost[x][y] >= 2) { ans = true; }
    }
    else {
        for (int i = 0; i < 4; i++) {
            int x2 = x + mx[i];
            int y2 = y + my[i];

            if (x2 < 0 || x2 >= 5 || y2 < 0 || y2 >= 5) { continue; }
            if (board[x2][y2] == -1) { continue; }
            
            if (board[x2][y2] == 1) { cost[x2][y2] = max(cost[x2][y2], cost[x][y] + 1); }
            else { cost[x2][y2] = max(cost[x2][y2], cost[x][y]); }

            board[x][y] = -1;
            dfs(x2, y2, d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x, y;

    for (int i = 0; i < 5; i++) {
        vector<int> v;
        vector<int> v2;
        for (int k = 0; k < 5; k++) {
            cin >> n;
            v.push_back(n);
            v2.push_back(0);
        }
        cost.push_back(v2);
        board.push_back(v);
    }

    cin >> x >> y;
    dfs(x, y, 0);
    cout << ans;

    return 0;
}