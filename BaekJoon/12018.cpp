#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
1) �����뼱�� ���ڸ� ����
�װź��� ���ų� ���⸸ �ϸ� ��
mile�迭�� ���� ������ �� �������� �����ϰ� ������ ������ sub�迭�� ����
*��û ���� �����ο����� ���ٸ� 1������ ��û ����
sub�迭�� 1 ����

2) �ִ�� ���� �� �ִ� ���� ���� ���ϱ�
sub�迭�� ������������ �����ϰ�
���ϸ����� �����鼭 ��û������ ���� ���� ���ϱ�
*/

int sub[100];
int mile[100];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, i, num, limit, j, count = 0;
    cin >> n >> m; // ���� ��, �־��� ���ϸ���

    for (i = 0; i < n; i++) {
        cin >> num >> limit; // ��û ��, �����ο�
        for (j = 0; j < num; j++) { cin >> mile[j]; }

        if (num < limit) { sub[i] = 1; continue; }

        sort(mile, mile + num, greater<int>()); // ��������
        sub[i] = mile[limit - 1];
    }

    sort(sub, sub + n); // ��������

    for (i = 0; i < n; i++) {
        count++; m -= sub[i];
        if (m < 0) { count--; break; }
    }
    cout << count;

    return 0;
}