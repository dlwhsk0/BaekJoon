#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[10001] = { 0 };
    int k, n, count, res = 0;
    cin >> k >> n;

    for (int i = 0; i < k; i++) { // k���� ���� ���� �Է�
        cin >> arr[i];
    }

    // k���� ���� �� �ִ� ���ϱ�
    int max = *max_element(arr, arr + k);

    long long low, mid, high; // ���� Ž�� ���� ����
    low = 1; high = max;

    while (low <= high) {
        mid = (low + high) / 2;
        count = 0;

        // ��������� ���� ���� �ջ�
        for (int i = 0; i < k; i++) {
            count += arr[i] / mid;
        }

        // mid ���̷� �߶��� ��
        // n�� �̻��� ������ ��������� �� ���
        // �� ��������� �� ª��
        if (count >= n) {
            low = mid + 1;
            if (res < mid) res = mid;
        }
        else { high = mid - 1; }
    }

    cout << res;

    /* �ð��ʰ� �ݺ��� �ڵ�
    for(int i=max; i>0; i--) {
        count = 0;

        for(int a=0; a<k; a++) {
            count += arr[a]/i;
        }

        if(count >= n) {
            cout << i;
            break;
        }
    }*/

    return 0;
}