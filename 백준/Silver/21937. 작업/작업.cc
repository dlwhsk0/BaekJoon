#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

// x에서 역방향으로 dfs, 노드 갯수 카운트

vector<int> v[100005];
bool visited[100005];
int n, m, src;

int dfs(int s) {
    int ans = 0;

    for (auto i : v[s]) {
        if (visited[i]) { continue; } // 방문 여부
        else {
            visited[i] = true;
            ans += dfs(i) + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    cin >> src;

    cout << dfs(src);

    return 0;
}