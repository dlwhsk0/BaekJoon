#include <iostream>

using namespace std;

/*
�Է��� ���� ������ A+B�� ����ϴ� ����. EOF�� ���� �˾� ������.
cin.eof() Ȱ��: cin���� �Է¹��� ���� ������ true ��ȯ
*/

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int a, b;

    while (true) {
        cin >> a >> b;
        if (cin.eof()) { return 0; }
        else { cout << a + b << endl; }
    }

    return 0;
}
