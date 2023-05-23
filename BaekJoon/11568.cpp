#include <iostream>
using namespace std;

/*
dp ���
LIS ���� ���� �κ� ����: ���� �� �����ϴ� �κ� ���� ���ϱ�

��� ���ҿ� �� ���� ������ ���ڵ��� �˻�
if ���� ���ڰ� ���� ���ں��� ũ�� && ���� ���� dp�� ���� ���� dp+1���� �۴�:
    ���� ���� dp = ���� ���� dp + 1 ����

�� ������ ��ġ�� dp�� ���� ū ���� lis�� ���̰� �ȴ�
*/

int card[1000];
int dp[1000];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, j, lis = 0;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> card[i];
        dp[i] = 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (card[i] > card[j] && dp[i] < (dp[j] + 1)) { dp[i] = dp[j] + 1; }
        }
    }

    for (i = 0; i < n; i++) { lis = max(lis, dp[i]); }
    cout << lis;


    return 0;
}