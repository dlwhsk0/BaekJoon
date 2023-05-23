#include <iostream>
#include <string> // string
#include <cctype> // 대소문자 판별
using namespace std;

/*
ans = 최소 문자열의 길이만큼은 눌러야함
캡스 키가 한영 키 (처음엔 비활성 상태)
*/

int main() {
    bool caps = 0, upper; // 마름모
    string str;
    cin >> str;

    int ans = str.length();
    int len = ans;

    for (int i = 0; i < len; i++) {
        upper = isupper(str[i]); // 대문자인지 판별

        if (upper && caps == 0) { // 대문자고 캡스가 비활성:
            caps = 1; // 캡스 활성화
            ans++;

            if (i < len - 1) { // 대문자 연속 검사
                if (islower(str[i + 1])) { caps = 0; }
            }
        }
        else if (upper == 0 && caps) { // 소문자고 캡스가 활성화:
            caps = 0; // 캡스 비활성화
            ans++;

            if (i < len - 1) { // 소문자 연속 검사
                if (isupper(str[i + 1])) { caps = 1; }
            }
        }
    }
    cout << ans;

    return 0;
}