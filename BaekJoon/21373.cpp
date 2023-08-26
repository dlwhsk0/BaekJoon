#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

// 스택사용

stack<int> s;

int calculate(int a, int b, char c) { // 계산기
    if (c == 'S') { return a - b; }
    else if (c == 'M') { return a * b; }
    else if (c == 'U') { return a / b; }
    else if (c == 'P') { return a + b; }
}

int make_number() { // 스택에 있는 숫자를 꺼내서 숫자 만들기
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

    cin >> n; // 연산자 개수 - 사용하지 않았음..
    cin >> str;

    len = str.length();
    for (int i = 0; i < len; i++) {
        // 숫자는 스택에 푸시
        if (str[i] >= '0' && str[i] <= '9') { s.push((int)(str[i] - '0')); }
        else { // 연산자
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

    if (prev == 'C') { // prev에 남아있는 연산자를 계산해준다
        check = true;
        cout << ans << " ";
    }
    else { ans = calculate(ans, temp, prev); }

    if (!check) { cout << "NO OUTPUT"; }

    return 0;
}