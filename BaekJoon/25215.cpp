#include <iostream>
#include <string> // string
#include <cctype> // ��ҹ��� �Ǻ�
using namespace std;

/*
ans = �ּ� ���ڿ��� ���̸�ŭ�� ��������
ĸ�� Ű�� �ѿ� Ű (ó���� ��Ȱ�� ����)
*/

int main() {
    bool caps = 0, upper; // ������
    string str;
    cin >> str;

    int ans = str.length();
    int len = ans;

    for (int i = 0; i < len; i++) {
        upper = isupper(str[i]); // �빮������ �Ǻ�

        if (upper && caps == 0) { // �빮�ڰ� ĸ���� ��Ȱ��:
            caps = 1; // ĸ�� Ȱ��ȭ
            ans++;

            if (i < len - 1) { // �빮�� ���� �˻�
                if (islower(str[i + 1])) { caps = 0; }
            }
        }
        else if (upper == 0 && caps) { // �ҹ��ڰ� ĸ���� Ȱ��ȭ:
            caps = 0; // ĸ�� ��Ȱ��ȭ
            ans++;

            if (i < len - 1) { // �ҹ��� ���� �˻�
                if (isupper(str[i + 1])) { caps = 1; }
            }
        }
    }
    cout << ans;

    return 0;
}