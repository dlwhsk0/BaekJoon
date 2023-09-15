#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// ���� Ʈ��: n���� ������ ��� ������ �� �ִ� n-1���� �������� �̷����
// 0���� w, b�� �����ϴ� �� ���� ��찡 ����
// DFS �ϸ鼭 ��� �����ư��鼭 ĥ�ϱ�

int white[100001]; // ��� ��ĥ���
int black[100001]; // ������ ��ĥ���
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
        if (!visit[y]) { // �湮���� �ʾ��� ���
            color = !color;
            dfs(y); // �� �ٲٸ鼭 ��������
        }
    }
    color = !color;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int a, b;

    for (int i = 0; i < n - 1; i++) { // ���� ���� �Է�
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 0; i < n; i++) { cin >> white[i] >> black[i]; } // ��ĥ ��� �Է�

    dfs(0); // 0�� ��尡 white�� ���

    ans = cnt; cnt = 0; fill_n(visit, n, 0); // �ʱ�ȭ
    dfs(0); // 0�� ��尡 black�� ���

    ans = min(cnt, ans); // �ּڰ� ����
    cout << ans;

    return 0;
}