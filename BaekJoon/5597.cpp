#include <iostream>
#include <algorithm> // max()
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool arr[31] = { 0 }; // 0: ������ 1: ����
    int num;

    for (int i = 1; i <= 28; i++) { // �Է� ���� ��ȣ�� �л� ���� ó��
        cin >> num;
        arr[num] = 1;
    }

    for (int i = 1; i <= 30; i++) { // ������ �л� ��ȣ ���
        if (arr[i] == 0) { cout << i << endl; }
    }

    return 0;
}
