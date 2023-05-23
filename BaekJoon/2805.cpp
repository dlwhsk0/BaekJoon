#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[1000000] = { 0 };
    int n, m;
    long long sum, height = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) { // n���� ���� ���� �Է�
        cin >> arr[i];
    }

    // n���� ���� �� �ִ� ���ϱ�
    long long max = *max_element(arr, arr + n);

    long long low, mid, high; // ���� Ž�� ���� ����
    low = 1; high = max;

    while (low <= high) {
        mid = (low + high) / 2;
        sum = 0;

        // �����ϰ� ���� ���� ����
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) sum += arr[i] - mid;
        }

        // mid ���̷� �������� ��
        // m �̻��� ������ ������ �� ����
        // ���ڶ�� �� ª��
        if (sum >= m) {
            low = mid + 1;
            if (height < mid) height = mid;
        }
        else { high = mid - 1; }
    }

    cout << height;

    return 0;
}