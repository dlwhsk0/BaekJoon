#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
0: ���� ���� 1: ���� �� ����(�湮��)

1. DFS�� ����� ��� ����� �湮�Ѵ�
2. ���� �켱 Ž���� �ݺ��ϴ� ���� ���ڿ� �湮�ϸ� ����

�ð� ���⵵: ??????????
*/

int n, m, ny, nx;
string map[1000];
bool flag = false;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 }; // ��, ��, ��, ��

void DFS(int y, int x) {
    map[y][x] = '1'; // �湮��
    if(y == m-1) { flag = true; return; } // ���� ���� �湮

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i]; // �����¿�

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) { continue; }
        if (map[ny][nx] == '0') { DFS(ny, nx); }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 0; i < m; i++) { cin >> map[i]; } // ���� �Է¹ޱ�

    for (int i = 0; i < n; i++) {
        if (map[0][i] == '0') {
            DFS(0, i);

            if (flag) { cout << "YES"; return 0; }
        }
    }
    
    if (flag) { cout << "YES"; }
    else { cout << "NO"; }

    return 0;
}