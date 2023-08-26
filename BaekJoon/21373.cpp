#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

// ���û��

stack<int> s;

int calculate(int a, int b, char c) { // ����
    if (c == 'S') { return a - b; }
    else if (c == 'M') { return a * b; }
    else if (c == 'U') { return a / b; }
    else if (c == 'P') { return a + b; }
}

int make_number() { // ���ÿ� �ִ� ���ڸ� ������ ���� �����
    int num = 0;
    for (int k = 0; s.size() > 0; k++) {
        num += s.top() * (int)pow(10, k);
        s.pop();
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int n, temp = -1, len, ans = 0;
    char prev = 'Z';
    bool check = false;

    cin >> n; // ������ ���� - ������� �ʾ���..
    cin >> str;

    len = str.length();
    for (int i = 0; i < len; i++) {
        // ���ڴ� ���ÿ� Ǫ��
        if (str[i] >= '0' && str[i] <= '9') { s.push((int)(str[i] - '0')); }
        else { // ������
            if (temp == -1) {
                temp = make_number();
                ans = temp;
            }
            else { temp = make_number(); }

            if (prev != 'Z') {
                if (prev == 'C') {
                    check = true;
                    cout << ans << " ";
                }
                else {
                    ans = calculate(ans, temp, prev);
                }
            }
            prev = str[i];
        }
    }

    if (prev == 'C') { // prev�� �����ִ� �����ڸ� ������ش�
        check = true;
        cout << ans << " ";
    }
    else { ans = calculate(ans, temp, prev); }

    if (!check) { cout << "NO OUTPUT"; }

    return 0;
}