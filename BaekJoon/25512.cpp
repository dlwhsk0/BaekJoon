#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 신장 트리: n개의 정점을 모두 연결할 수 있는 n-1개의 간선으로 이루어짐
// BFS? DFS? 하면서 흰백 번갈아가면서 칠하면 되는 거 아닐까 뭐가 더 빠른거지
// 0번을 w, b로 시작하는 두 가지 경우가 있음

int white[100001]; // 흰색 색칠비용
int black[100001]; // 검은색 색칠비용
bool visit[100001];
vector<int> v[100001];
int n;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << '\n';
        for (int i = 0; i < n; i++) {
            int y = v[x][i];
            if (!visit[y]) {
                q.push(y);
                visit[y] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 0; i < n; i++) { cin >> white[i] >> black[i] ; }

    bfs(0);

    return 0;
}