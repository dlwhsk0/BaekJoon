#include <iostream>
#include <algorithm>
using namespace std;

/*
���� ä�� �� �� �� ���� ���׳� ��ġ (������ ��ġ�� ������ ����)
��� �������� �Ÿ��� �� ���� �ּҰ� �ǵ���

�迭 ������ �� �߾Ӱ�
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;

    int* arr = new int[n];
    for (i = 0; i < n; i++) { cin >> arr[i]; }

    sort(arr, arr + n);
    cout << arr[(n - 1) / 2];

    return 0;
}