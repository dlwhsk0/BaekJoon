#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool moeum(char c) { // ���� üũ
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int i, idx;

    while (true) {
        idx = 0;

        cin >> str;
        if (str == "#") { return 0; } // ��

        for (i = 0; i < str.length(); i++) {
            if (i == 0 && moeum(str[i])) { // ù��° ���ĺ��� ������ ��� �ٷ� ay ���̱�
                break;
            }

            if (moeum(str[i])) {
                idx = i;
                break;
            }
        }

        if (idx == 0) {
            cout << str;
        }
        else {
            for (i = idx; i < str.length(); i++) {
                cout << str[i];
            }
            for (i = 0; i < idx; i++) {
                cout << str[i];
            }
        }

        cout << "ay\n";
    }

    return 0;
}