#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ans = 0, n;
    bool m, flag;
    string str;

    cin >> n;

    while (true) {
        m = true;
        str = to_string(n);

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') { // ���� �߿� 1�� �ִ� ���
                flag = false;
                string temp = "";
                for (int k = 0; k < str.length(); k++) {
                    if (k == i) { continue; } // �� 1�� ���� ���ο� 0�� �����

                    if (str[k] != '0') { flag = true; } // ���� ���̿� 0�� �ִ� ��� ���� ������ �ϱ�
                    if (flag) { temp += str[k]; }
                }
                str = temp;
                m = false;
                break;
            }
        }
        ans++;

        if (str == "") { break; } // ���ڰ� ���� ������ ���� ����

        n = stoi(str);
        if (m) { n--; }
    }

    cout << ans;

    return 0;
}