#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 신장 트리: n개의 정점을 모두 연결할 수 있는 n-1개의 간선으로 이루어짐
// 0번을 w, b로 시작하는 두 가지 경우가 있음
// DFS 하면서 흰백 번갈아가면서 칠하기

int white[100001]; // 흰색 색칠비용
int black[100001]; // 검은색 색칠비용
bool visit[100001];
vector<int> v[100001];
bool color; // 0: white, 1: black
int n;
long long cnt, ans;

void colorflag(int x) {
    if (color) { cnt += black[x]; }
    else { cnt += white[x]; }
}

void dfs(int x) {
    visit[x] = true;
    colorflag(x);

    for (int i = 0; i < v[x].size(); i++) {
        int y = v[x][i];
        if (!visit[y]) { // 방문하지 않았을 경우
            color = !color;
            dfs(y); // 색 바꾸면서 내려가기
        }
    }
    color = !color;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int a, b;

    for (int i = 0; i < n - 1; i++) { // 간선 정보 입력
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 0; i < n; i++) { cin >> white[i] >> black[i]; } // 색칠 비용 입력

    dfs(0); // 0번 노드가 white인 경우

    ans = cnt; cnt = 0; fill_n(visit, n, 0); // 초기화
    dfs(0); // 0번 노드가 black인 경우

    ans = min(cnt, ans); // 최솟값 저장
    cout << ans;

    return 0;
}