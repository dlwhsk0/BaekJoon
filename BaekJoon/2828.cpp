#include <iostream>
using namespace std;

/*
����� ������ ������,
�ٱ����� ���۰� ���� �ִ��� �˻�
���ۺ��� �տ� ������ �׸�ŭ �̵�
������ �ڿ� ������ �׸�ŭ �̵�
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, j, ans = 0, i, apple; // ��ũ��, �ٱ���, ��� ����, �̵��Ÿ�
    cin >> n >> m;
    
    cin >> j;
    int start = 1, end = m;

    for (i = 0; i < j; i++) {
        cin >> apple;
        if (start > apple) { // �������� �̵�
            ans += start - apple;
            start = apple;
            end = start + (m - 1);
        }
        else if (end < apple) { // ���������� �̵�
            ans += apple - end;
            end = apple;
            start = end - (m - 1);
        }
    }

    cout << ans;

    return 0;
}