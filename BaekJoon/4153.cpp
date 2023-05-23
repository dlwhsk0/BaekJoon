#include <iostream>
#include <algorithm> // sort()
#include <cmath> // pow()
#include <vector>
#include <string>

using namespace std;

/*
���� ���� ��
1. �� ���� ���� �迭�� �Է� �ޱ�
2. ������������ �����ϱ�
3. ��Ÿ��� ���� �˻�
*/

int main() {
    int arr[3] = { 0 };

    while (true) {
        cin >> arr[0] >> arr[1] >> arr[2]; // �� ���� ���� �Է�

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) { break; }
        else {
            sort(arr, arr + 3); // �������� ����

            if (pow(arr[2], 2) == (pow(arr[0], 2) + pow(arr[1], 2))) {
                cout << "right" << endl;
            } // ��Ÿ��� ����
            else {
                cout << "wrong" << endl;
            }
        }
    }

    return 0;
}