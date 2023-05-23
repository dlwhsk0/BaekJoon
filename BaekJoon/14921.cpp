#include <iostream>
#include <algorithm>
using namespace std;

/*
�� ������ �˰���:
����Ʈ�� ���������� �����ؾ��� �� �� ���� �� ��ġ�� ����ϸ� ó��

�ݺ��� {
0�� ����� �� ����
sum < 0: left 1 ����
sum > 0: right 1 ����
sum == 0: �� ã�� break �ϰ� �� ��� }
*/

int arr[100000];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, left, answer, right, sum;
    cin >> n;

    answer = 200000000;
    left = 0; right = n - 1;

    for (i = 0; i < n; i++) { cin >> arr[i]; }
    sort(arr, arr + n);

    while (left < right) {
        sum = arr[left] + arr[right]; // ��� ���ϱ�
        if (abs(sum) < abs(answer)) { answer = sum; } // 0�� �� ����� �� ����

        if (sum == 0) { break; }
        else if (sum < 0) { left++; }
        else { right--; }
    }

    cout << answer;

    return 0;
}

