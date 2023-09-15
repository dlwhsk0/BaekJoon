#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// ���� Ʈ��: n���� ������ ��� ������ �� �ִ� n-1���� �������� �̷����
// BFS? DFS? �ϸ鼭 ��� �����ư��鼭 ĥ�ϸ� �Ǵ� �� �ƴұ� ���� �� ��������
// 0���� w, b�� �����ϴ� �� ���� ��찡 ����

int white[100001]; // ��� ��ĥ���
int black[100001]; // ������ ��ĥ���
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