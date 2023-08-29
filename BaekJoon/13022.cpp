#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

char wolf[4] = { 0, };
bool ans = true;
vector<char> v;

void check() { // �� ���ĺ��� ������ �Ȱ��� Ȯ���ϴ� �Լ�
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (wolf[i] != wolf[j]) { ans = false; }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int n, len;

    cin >> str;
    len = str.length();

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'w') { wolf[0]++; }
        else if (str[i] == 'o') { wolf[1]++; }
        else if (str[i] == 'l') { wolf[2]++; }
        else if (str[i] == 'f') {
            wolf[3]++;

            if (str[i + 1] == 'w') { check(); }
        }

        //if (i >= 1) { // ������ �´��� �˻�
        //    if (str[i] == 'w') {
        //        if (str[i - 1] == 'w' || str[i - 1] == 'f') { v.push_back(str[i]); }
        //        else { ans = false; }
        //    }
        //    else if (str[i] == 'o') {
        //        if (str[i - 1] == 'o' || str[i - 1] == 'w') { v.push_back(str[i]); }
        //        else { ans = false; }
        //    }
        //    else if (str[i] == 'l') {
        //        if (str[i - 1] == 'l' || str[i - 1] == 'o') { v.push_back(str[i]); }
        //        else { ans = false; }
        //    }
        //    else if (str[i] == 'f') {
        //        if (str[i - 1] == 'l' || str[i - 1] == 'f') { v.push_back(str[i]); }
        //        else { ans = false; }
        //    }
        //}
        if (i >= 1) { // ������ �´��� �˻�
            if (str[i] == 'w') {
                if (!(str[i - 1] == 'w' || str[i - 1] == 'f')) { ans = false; }
            }
            else if (str[i] == 'o') {
                if (!(str[i - 1] == 'o' || str[i - 1] == 'w')) { ans = false; }
            }
            else if (str[i] == 'l') {
                if (!(str[i - 1] == 'l' || str[i - 1] == 'o')) { ans = false; }
            }
            else if (str[i] == 'f') {
                if (!(str[i - 1] == 'l' || str[i - 1] == 'f')) { ans = false; }
            }
        }
    }

    check(); // ���������� �ٽ� �˻�

    if (ans) { cout << 1; }
    else { cout << 0; }

    return 0;
}