#include <iostream>
#include <algorithm>

using namespace std;

/*
new: heap�� �޸𸮸� ������ �� �ּ� ����
delete: �ش� �ּ��� �޸𸮸� ����

int* ptr = new int;
delete ptr;

int* ptr = new int[2];
delete[] ptr;
*/

int main() {
    int n; // ���Ƹ� ���� �ʱ� ����
    cin >> n;

    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++) { // �ʱ� ��
        arr[i] = 0;
    }

    int m; // ������ �ൿ Ƚ��
    cin >> m;

    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;

        for (int j = x; j < y; j++) {
            arr[j] = 1; // ������ �� �㹰��
        }
        if (arr[y] != 1) { arr[y] = -1; } // ���� �� �㹰��
    }

    int count = 0;
    for (int i = 1; i <= n; i++) { // �� ����
        if (arr[i] == 0 || arr[i] == -1) { count++; }
    }

    cout << count;

    return 0;
}
