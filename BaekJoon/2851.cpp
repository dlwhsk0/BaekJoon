#include <iostream>
using namespace std;

/*
10�� �ݺ� { �Է� �ޱ� }
10�� �ݺ� {
    100�� �ѱ� ������ �հ� ����
    100�� ������ ���� �հ�� ���ؼ� 100�� ����� �� ��� �� �ߴ�
}
*/

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[10] = { 0 };
    int i, sum = 0, temp, a, b;

    for (i = 0; i < 10; i++) { cin >> arr[i]; }

    for (i = 0; i < 10; i++) {
        temp = arr[i];
        sum += temp;

        if (sum >= 100) { break; }
    }

    a = 100 - (sum - temp);
    b = sum - 100;

    if (a == b || a > b) { cout << sum; }
    else { cout << sum - temp; }

    return 0;
}